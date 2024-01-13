import csv
import sys


def main():

    # TODO: Check for command-line usagex
    if len(sys.argv) != 3:
        print('Usage: python dna.py [individual].csv [sequence].txt')
        return

    # TODO: Read database file into a variable
    data = []
    with open(sys.argv[1], 'r') as file_p:
        reader = csv.DictReader(file_p)

        for row in reader:
            data.append(row)
        fields = reader.fieldnames

    # TODO: Read DNA sequence file into a variable
    sqc = ''
    with open(sys.argv[2], 'r') as file_s:
        for s in file_s:
            sqc += s

    # TODO: Find longest match of each STR in DNA sequence
    fields = fields[1:]
    fields = {Str: None for Str in fields}

    for field in fields:
        fields[field] = str(longest_match(sqc, field))

    # TODO: Check database for matching profiles
    found = False
    for d in data:

        for key in list(fields.keys()):
            if fields[key] == d[key]:
                found = True
            else:
                found = False
                break

        if found:
            print(d['name'])
            return

    print('No match')
    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
