def is_interesting(N):
    N_string = str(N)
    digit_product = 1
    digit_sum = 0
    for i in range(len(N_string)):
        digit_product *= ord(N_string[i]) - ord('0')
        digit_sum += ord(N_string[i]) - ord('0')
    return digit_product % digit_sum == 0


def interesting_integers(A, B):
    res = 0
    for n in range(A, B + 1):
        if is_interesting(n):
            res += 1
    return res


if __name__ == '__main__':
    T = int(input())
    for t in range(T):
        A, B = [int(x) for x in input().split()]
        print(f'Case #{t + 1}: {interesting_integers(A, B)}')
