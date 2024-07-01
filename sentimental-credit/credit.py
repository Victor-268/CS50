from cs50 import get_int
from cs50 import get_string

# Function to check if the card number is valid using Luhn's algorithm
def is_valid(card_number):
    total_sum = 0

    # Starting from the rightmost digit, double every second digit
    for i in range(len(card_number) - 2, -1, -2):
        digit = int(card_number[i]) * 2

        # If doubling results in a two-digit number, add the digits
        if digit > 9:
            digit = digit // 10 + digit % 10

        total_sum += digit

    # Add the remaining digits
    total_sum += sum(int(digit) for digit in card_number[-1::-2])

    # Check if the total sum is a multiple of 10
    return total_sum % 10 == 0

n = get_string("Number: ")

if n[0:2] in ['34','37'] and len(n) == 15 and is_valid(n):
    print("AMEX")
elif n[0:2] in ['51', '52', '53', '54', '55'] and  len(n) == 16 and is_valid(n):
    print("MASTERCARD")
elif n[0] == '4' and len(n) in [13, 16] and is_valid(n):
    print("VISA")
else:
    print("INVALID")
