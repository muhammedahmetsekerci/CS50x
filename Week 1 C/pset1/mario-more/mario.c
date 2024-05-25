#include <stdio.h>
#include <cs50.h>

void space(int n);
void box(int n);
void boxprint(int n);

int main(void)
{
    int n;
    // Check if the number is greater than 0
    do
    {
        n = get_int("n: ");
    } while (n < 1);

    box(n);
}

// Writes # according to the entered number
void box(int n)
{
    int a = n - 1;
    for (int i = 1; i <= n; i++)
    {
        space(a);
        boxprint(i);
        space(2);
        boxprint(i);
        printf("\n");
        a--;
    }
}

// space printing function
void space(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf(" ");
    }
}

// #draw function
void boxprint(int n)
{
    for (int j = 1; j <= n; j++)
    {
        printf("#");
    }
}