def main():
    text = input('Text: ')

    l = letters(text)
    w = words(text)
    s = sentences(text)

    l_sum = (l / w) * 100
    s_sum = (s / w) * 100

    coleman = 0.0588 * l_sum - 0.296 * s_sum - 15.8

    r = round(coleman)

    if r < 1:
        print('Before Grade 1')
    elif r >= 16:
        print('Grade 16+')
    else:
        print(f'Grade: {r}')


def letters(text):
    chr_count = 0
    for c in text:
        if c.isalpha():
            chr_count += 1
    return chr_count


def words(text):
    words_count = 0

    for c in text:
        if c.isspace():
            words_count += 1

    if not text:
        return words_count
    else:
        return words_count + 1


def sentences(text):
    sen_count = 0

    for c in text:
        if c == '.' or c == '?' or c == '!':
            sen_count += 1
    return sen_count


if __name__ == '__main__':
    main()