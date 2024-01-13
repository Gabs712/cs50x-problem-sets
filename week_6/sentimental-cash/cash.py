def main():
    n = get_float()
    print(get_coins(n))


def get_float():
    while True:
        try:
            n = (input('Change owed: '))
            if float(n) < 0 or len(n) > 4:
                raise ValueError

            return float(n) * 100
        except ValueError:
            continue


def get_coins(n):
    coins = 0

    while n > 0:
        if n >= 25:
            n = n - 25
            coins += 1
        elif n >= 10:
            n = n - 10
            coins += 1
        elif n >= 5:
            n = n - 5
            coins += 1
        elif n >= 1:
            n = n - 1
            coins += 1
    return coins


if __name__ == '__main__':
    main()