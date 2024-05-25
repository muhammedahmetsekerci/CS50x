#include <stdio.h>
#include <cs50.h>

int luhnAlgorithm(long n);
int mode(long n, int m);
int cardDigitControl(long n);
void cardControl(long n);
int firstTwoDigits(long n);
int firstDigits(long n);

int main(void)
{
    long cnumber;
    cnumber = get_long("Enter Card Number: ");

    // card number algorithm total last digit 0 check
    if (luhnAlgorithm(cnumber) % 10 == 0)
    {
        cardControl(cnumber);
    }
    else
    {
        printf("INVALID\n");
    }
}

// Luhn Algorithm
int luhnAlgorithm(long n)
{
    int a = 0, b = 0, k = 0, c = 0;

    while (n > 0)
    {
        c = 0;
        k += mode(n, 10);
        n /= 10;
        b = (mode(n, 10)) * 2;
        if (b >= 10)
        {
            do
            {
                c += mode(b, 10);
                b /= 10;
            } while (b > 0);
            b = c;
        }
        a += b;
        n /= 10;
    }
    a += k;

    return a;
}

int mode(long n, int m)
{
    return n % m;
}

// Checking how many digits the card has
int cardDigitControl(long n)
{
    int digit = 0;
    do
    {
        n /= 10;
        digit++;
    } while (n > 0);

    return digit;
}

// Check which card it is
void cardControl(long n)
{
    int digit = cardDigitControl(n);
    if (digit == 16)
    {
        n = firstTwoDigits(n);
        if (n == 51 || n == 52 || n == 53 || n == 54 || n == 55)
        {
            printf("MASTERCARD\n");
        }
        else if (n / 10 == 4)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else if (digit == 15)
    {
        n = firstTwoDigits(n);

        if (n == 34 || n == 37)
        {
            printf("AMEX\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else if (digit == 13)
    {
        n = firstDigits(n);

        if (n == 4)
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
}

// finds the first digit of the number
int firstDigits(long n)
{
    do
    {
        n /= 10;
    } while (n > 10);
    return n;
}

// finds the first two digits of the number
int firstTwoDigits(long n)
{
    do
    {
        n /= 10;
    } while (n > 99);
    return n;
}
