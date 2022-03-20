def number_of_palindromes(N, K, S):
    middle = (N - 1) // 2
    res = 1 if S[:middle + 1][::-1] < S[-1:- middle - 2: - 1][::-1] else 0
    power = 1
    for i in range(middle, -1, -1):
        res += (ord(S[i]) - ord('a')) * power
        power *= K
    return res % 1000000007


if __name__ == '__main__':
    T = int(input())
    for t in range(T):
        N, K = [int(x) for x in input().split()]
        S = input()
        print(f'Case #{t + 1}: {number_of_palindromes(N, K, S)}')
