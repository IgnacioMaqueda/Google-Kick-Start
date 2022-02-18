def main():
    T = int(input())
    for t in range(T):
        N, M = [int(x) for x in input().split()]
        C = [int(x) for x in input().split()]
        print(f'Case #{t + 1}: {sum(C) % M}')


if __name__ == '__main__':
    main()
