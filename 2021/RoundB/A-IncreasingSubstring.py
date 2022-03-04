def longest_increasing_substrings(N, S):
    res = [1]
    current = 1
    for i in range(1, N):
        if S[i - 1] < S[i]:
            current += 1
        else:
            current = 1
        res.append(current)
        i += 1
    return res


if __name__ == '__main__':
    T = int(input())
    for t in range(T):
        N = int(input())
        S = input()
        print(f"Case #{t + 1}: ", end='')
        print(*longest_increasing_substrings(N, S))
