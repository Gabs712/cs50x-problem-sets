while True:
    try:
        height = int(input('height: '))
        if not 1 <= height <= 8:
            raise ValueError
        break
    except ValueError:
        continue

for i in range(height):
    for _ in range(height - i - 1):
        print(' ', end='')
    for _ in range(i + 1):
        print('#', end='')

    print('  ', end='')

    for _ in range(i + 1):
        print('#', end='')
    print()