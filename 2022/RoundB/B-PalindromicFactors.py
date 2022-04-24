def is_palindromic(n):
    s = str(n)
    return s == s[::-1]


def palindromic_factors(A):
    res = 0
    i = 1
    while i * i <= A:
        if A % i == 0:
            if is_palindromic(i):
                res += 1
            j = A // i
            if j != i and is_palindromic(j):
                res += 1
        i += 1
    return res


if __name__ == '__main__':
    T = int(input())
    for t in range(T):
        A = int(input())
        print(f"Case #{t + 1}: {palindromic_factors(A)}")
