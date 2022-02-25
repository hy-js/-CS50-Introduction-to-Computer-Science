#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompts user for credit card number
    long cc = get_long("Number: ");

    int digit;
    long lastDigit, secondLastDigit, checksum;
    long total = 0;
    long total2 = 0;
    int i = 0;

    // Calculate cheksum:
    checksum = cc;
    while (checksum > 0)
    {
        lastDigit = checksum % 10;
        checksum /= 10;
        secondLastDigit = (checksum % 10) * 2;
        checksum /= 10;
        total += lastDigit;
        while (secondLastDigit > 0)
        {
            digit = secondLastDigit % 10;
            total2 += digit;
            secondLastDigit /= 10;
        }
    }
    total = total2 + total;
    digit = total % 10;
    // Not VALID
    if (digit != 0)
    {
        printf("INVALID\n");
    }
    else
    {
        long firstDigit = cc, twoFirstDigits = cc;
        int len = 0;
        while (cc)
        {
            lastDigit = cc % 10;
            twoFirstDigits = firstDigit;
            firstDigit = cc;
            cc /= 10;
            len++;
        }

        if (twoFirstDigits == 34 || twoFirstDigits == 37)
        {
            printf("AMEX\n");
        }
        else if (twoFirstDigits == 51 || twoFirstDigits == 52 || twoFirstDigits == 53 || twoFirstDigits == 54 || twoFirstDigits == 55)
        {
            printf("MASTERCARD\n");
        }
        else if (lastDigit == 4 && len >= 13)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
}