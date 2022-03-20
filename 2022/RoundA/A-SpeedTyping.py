def letters_to_remove(I, P):
    j = 0
    for c in I:
        while j < len(P) and P[j] != c:
            j += 1
        if j == len(P):
            return "IMPOSSIBLE"
        j += 1
    return len(P) - len(I)


if __name__ == '__main__':
    T = int(input())
    for t in range(T):
        I = input()
        P = input()
        print(f'Case #{t + 1}: {letters_to_remove(I, P)}')
