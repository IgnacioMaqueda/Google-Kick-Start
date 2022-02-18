def get_ruler(kingdom):
    last_letter = kingdom.lower()[-1]
    if last_letter in ['a', 'e', 'i', 'o', 'u']:
        ruler = 'Alice'
    elif last_letter == 'y':
        ruler = 'nobody'
    else:
        ruler = 'Bob'
    return ruler


def main():
    # Get the number of test cases
    T = int(input())
    for t in range(T):
        # Get the kingdom
        kingdom = input()
        print(f'Case #{t + 1}: {kingdom} is ruled by {get_ruler(kingdom)}.')


if __name__ == '__main__':
    main()
