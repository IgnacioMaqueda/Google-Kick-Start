import math


def obtain_area(radius):
    return math.pi * radius * radius


def sum_of_areas(R, A, B):
    res = obtain_area(R)
    while R > 0:
        R = R * A
        res += obtain_area(R)
        R = R // B
        res += obtain_area(R)
    return res


if __name__ == '__main__':
    T = int(input())
    for t in range(T):
        R, A, B = [int(x) for x in input().split()]
        print(f"Case #{t + 1}: {sum_of_areas(R, A, B)}")
