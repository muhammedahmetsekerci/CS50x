#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    string word1 = get_string("Player 1 word is: \n");
    string word2 = get_string("Player 2 word is: \n");
    int p1sum = 0;
    int p2sum = 0;

    string array1 = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    int array2[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
    for (int i = 0, a = strlen(array1); i < a; i++)
    {
        for (int j = 0; j < strlen(word1); j++)
        {
            if (array1[i] == toupper(word1[j]))
            {
                p1sum = p1sum + array2[i];
            }
        }
        for (int k = 0; k < strlen(word2); k++)
        {
            if (array1[i] == toupper(word2[k]))
            {
                p2sum = p2sum + array2[i];
            }
        }
    }

    if (p1sum > p2sum)
    {
        printf("Player 1 wins!\n");
    }
    else if (p2sum > p1sum)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}