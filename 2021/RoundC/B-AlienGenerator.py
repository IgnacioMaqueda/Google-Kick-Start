def number_of_K_values(G):
    res = 1
    i = 2
    while (i * (i + 1)) // 2 <= G:
        if G % i == ((i * (i - 1)) // 2) % i:
            res += 1
        i += 1
    return res


if __name__ == '__main__':
    T = int(input())
    for t in range(T):
        G = int(input())
        print(f'Case #{t + 1}: {number_of_K_values(G)}')
