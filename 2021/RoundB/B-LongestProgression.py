def longest_without_changes(M, difs):
    res = 2
    current = 2
    for i in range(1, M):
        if difs[i] == difs[i - 1]:
            current += 1
        else:
            res = max(res, current)
            current = 2
    return max(res, current)


def longest_arithmetic_subarray_length(N, A):
    difs = []
    for i in range(1, N):
        difs.append(A[i] - A[i - 1])
    res = min(N, longest_without_changes(N - 1, difs) + 1)
    for i in range(0, N - 2):
        if (difs[i] + difs[i + 1]) % 2 == 0:
            difference = (difs[i] + difs[i + 1]) // 2
            l = i - 1
            while l >= 0 and difs[l] == difference:
                l -= 1
            r = i + 2
            while r < N - 1 and difs[r] == difference:
                r += 1
            res = max(res, r - l)
    return res


if __name__ == '__main__':
    T = int(input())
    for t in range(T):
        N = int(input())
        A = [int(x) for x in input().split()]
        print(f"Case #{t + 1}: {longest_arithmetic_subarray_length(N, A)}")
