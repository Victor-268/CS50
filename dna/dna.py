import csv
import sys

def main():
    # Check for command-line usage
    if not len(sys.argv) == 3:
        print("Usage: python script.py database.csv sequence.txt")
        return

    # Read database file into a variable
    try:
        with open(sys.argv[1]) as file:
            reader = csv.DictReader(file)
            rows = list(reader)
    except FileNotFoundError:
        print(f"Error: The file {sys.argv[1]} does not exist.")
        return
    except Exception as e:
        print(f"Error reading {sys.argv[1]}: {e}")
        return

    # Read DNA sequence file into a variable
    try:
        with open(sys.argv[2]) as f:
            sequence = f.read().strip()
    except FileNotFoundError:
        print(f"Error: The file {sys.argv[2]} does not exist.")
        return
    except Exception as e:
        print(f"Error reading {sys.argv[2]}: {e}")
        return

    # Create a list of STRs from the database header
    if rows:
        str_list = list(rows[0].keys())[1:]
    else:
        print("Error: The database is empty.")
        return

    # Find longest match of each STR in DNA sequence
    result = []
    for subsequence in str_list:
        result.append(longest_match(sequence, subsequence))

    # Check database for matching profiles
    for row in rows:
        profile = [int(row[str_count]) for str_count in str_list]
        if profile == result:
            print(row['name'])
            return

    print("No match")

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
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in sequence, return longest run found
    return longest_run

if __name__ == "__main__":
    main()
