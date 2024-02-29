#include <cs50.h>
#include <stdio.h>

int getFirstTwoDigits(long long int number)
{
    // Ensure the number is positive
    if (number < 0)
    {
        number = -number;
    }

    // Extract the first two digits
    while (number >= 100)
    {
        number /= 10;
    }

    return (int) number;
}

int getLength(long long int number)
{
    // Ensure the number is positive
    if (number < 0)
    {
        number = -number;
    }

    // Count digits by dividing by 10 until the number becomes 0
    int length = 0;
    while (number > 0)
    {
        number /= 10;
        length++;
    }

    return length;
}

int main(void)
{
    long long int n;
    do
    {
        n = get_long("Card number: ");
    }
    while (n < 0);

    int firstTwoDigits = getFirstTwoDigits(n);
    int length = getLength(n);
    int digit, sum = 0;
    int position = 1;
    long long int number = n;

    while (number > 0)
    {
        digit = number % 10;

        if (position % 2 == 0)
        {
            digit *= 2;

            if (digit >= 10)
            {
                digit = digit % 10 + digit / 10;
            }
        }

        sum += digit;
        number /= 10;
        position++;
    }

    if (sum % 10 == 0)
    {
        if ((length == 15) && (firstTwoDigits == 34 || firstTwoDigits == 37))
        {
            printf("AMEX\n");
        }
        else if ((length == 16) && (firstTwoDigits >= 51 && firstTwoDigits <= 55))
        {
            printf("MASTERCARD\n");
        }
        else if ((length == 13 || length == 16) && (firstTwoDigits / 10 == 4))
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }

    return 0;
}
