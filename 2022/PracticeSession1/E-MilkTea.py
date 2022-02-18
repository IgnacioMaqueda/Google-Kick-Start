def min_complaints(N, M, P, preferences, forbidden):
    complaints = P * N + 1
    forbidden.append(-1)
    forbidden.sort()
    forbidden.append(2 ** P)
    for i in range(M + 1):
        for k in range(forbidden[i] + 1, forbidden[i + 1]):
            k_complaints = 0
            for j in range(N):
                k_complaints += bin(k ^ preferences[j]).count('1')
            if k_complaints < complaints:
                complaints = k_complaints
    return complaints


if __name__ == '__main__':
    T = int(input())

    for t in range(1, T + 1):
        N, M, P = map(int, input().split())
        preferences = [int(input(), 2) for _ in range(N)]
        forbidden = [int(input(), 2) for _ in range(M)]

        print(f"Case #{t}: {min_complaints(N, M, P, preferences, forbidden)}")
