def recursive_function(N, D, V, i, j, res):
    if i > j:
        return res
    rest_i = V[i]
    sum_i = D - V[i]
    rest_j = V[j]
    sum_j = D - V[j]
    best_rest = min(rest_i, rest_j)
    best_sum = min(sum_i, sum_j)
    if best_rest < best_sum:
        for k in range(i, j + 1):
            V[k] = (D + V[k] - best_rest) % D
        res += best_rest
        while i < N and V[i] == 0:
            i += 1
        while j >= 0 and V[j] == 0:
            j -= 1
        return recursive_function(N, D, V, i, j, res)
    elif best_sum < best_rest:
        for k in range(i, j + 1):
            V[k] = (D + V[k] + best_sum) % D
        res += best_sum
        while i < N and V[i] == 0:
            i += 1
        while j >= 0 and V[j] == 0:
            j -= 1
        return recursive_function(N, D, V, i, j, res)
    else:
        new_V = V[:]
        res += best_rest
        for k in range(i, j + 1):
            V[k] = (D + V[k] - best_rest) % D
        while i < N and V[i] == 0:
            i += 1
        while j >= 0 and V[j] == 0:
            j -= 1
        for k in range(i, j + 1):
            new_V[k] = (D + new_V[k] + best_sum) % D
        while i < N and new_V[i] == 0:
            i += 1
        while j >= 0 and new_V[j] == 0:
            j -= 1
        return min(recursive_function(N, D, V, i, j, res), recursive_function(N, D, new_V, i, j, res))



def minimum_operations(N, D, V):
    res = 0
    i = 0
    j = N - 1
    while i < N and V[i] == 0:
        i += 1
    while j >= 0 and V[j] == 0:
        j -= 1
    return recursive_function(N, D, V, i, j, res)


if __name__ == '__main__':
    T = int(input())
    for t in range(T):
        N, D = [int(x) for x in input().split()]
        V = [int(v) for v in input().split()]
        print(f"Case #{t + 1}: {minimum_operations(N, D, V)}")
