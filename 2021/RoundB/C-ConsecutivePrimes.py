from math import sqrt, floor


def is_prime(n):
    if n == 1:
        return False
    if n == 2:
        return True
    if n % 2 == 0:
        return False
    k = 3
    while k * k <= n:
        if n % k == 0:
            return False
        k += 2
    return True


def next_prime(n):
    if n % 2 == 0:
        n += 1
    while True:
        if is_prime(n):
            return n
        n += 2


def previous_prime(n):
    if n == 3:
        return 2
    n -= 1
    if n % 2 == 0:
        n -= 1
    while True:
        if is_prime(n):
            return n
        n -= 2


def secret_code(Z):
    root = floor(sqrt(Z)) + 1
    previous = previous_prime(root)
    nextp = next_prime(root)
    if previous * nextp <= Z:
        return previous * nextp
    return previous * previous_prime(previous)


if __name__ == '__main__':
    T = int(input())
    for t in range(T):
        Z = int(input())
        print(f"Case #{t + 1}: {secret_code(Z)}")
