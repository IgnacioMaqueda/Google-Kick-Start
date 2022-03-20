def new_number(N):
    digits_sum = 0
    for c in N:
        digits_sum += ord(c) - ord('0')
    new_digit = chr(9 - (digits_sum % 9) + ord('0'))
    if new_digit == '9':
        return N[:1] + '0' + N[1:]
    i = 0
    while i < len(N) and N[i] <= new_digit:
        i += 1
    return N[:i] + new_digit + N[i:]


if __name__ == '__main__':
    T = int(input())
    for t in range(T):
        N = input()
        print(f'Case #{t + 1}: {new_number(N)}')
