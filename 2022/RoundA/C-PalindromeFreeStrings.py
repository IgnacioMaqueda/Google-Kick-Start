def is_palindrome(S, i, j):
    for k in range((j - i + 1) // 2):
        if S[i + k] != S[j - k]:
            return False
    return True


def has_palindrome(S, previous, current):
    for j in range(previous + 1, current):
        for i in range(0, j - 3):
            if is_palindrome(S, i, j):
                return True
    return False


def is_possible(N, S, i, prev):
    while i < N and S[i] != '?':
        i += 1
    if i == N:
        return not has_palindrome(S, prev, N)
    S_0 = S[:i] + '0' + S[i + 1:]
    S_1 = S[:i] + '1' + S[i + 1:]
    return (not has_palindrome(S_0, prev, i + 1) and is_possible(N, S_0, i + 1, i)) or (
            not has_palindrome(S_1, prev, i + 1) and is_possible(N, S_1, i + 1, i))


def is_possible_to_assign(N, S):
    return "POSSIBLE" if is_possible(N, S, 0, -1) else "IMPOSSIBLE"


if __name__ == '__main__':
    T = int(input())
    for t in range(T):
        N = int(input())
        S = input()
        print(f'Case #{t + 1}: {is_possible_to_assign(N, S)}')
