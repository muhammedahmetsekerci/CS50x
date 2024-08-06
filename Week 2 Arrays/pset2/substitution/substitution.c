#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

void substitution(string plaintext, string text);
bool arrayStringControl(char array[]);

int main(int argc, string argv[])
{

    if (argc != 2 || (arrayStringControl(argv[1]) == false))
    {
        printf("Usage: ./substitution key");
        return 1;
    }
    else if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.");
        return 1;
    }
    else
    {
        string plaintext = get_string("plaintext: ");
        substitution(plaintext, argv[1]);
    }

    return 0;
}

void substitution(string plaintext, string text)
{
    int z = strlen(plaintext);
    char cipherText[50];
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int i = 0, a = strlen(plaintext); i < a; i++)
    {
        for (int k = 0, l = strlen(alphabet); k < l; k++)
        {
            if (!isalpha(plaintext[i]) || isspace(plaintext[i]))
            {
                cipherText[i] = (plaintext[i]);
                break;
            }
            if (toupper(alphabet[k]) == toupper(plaintext[i]))
            {
                if ((plaintext[i] >= 'a' && plaintext[i] <= 'z') && (text[k] >= 'a' && text[k] <= 'z'))
                {
                    cipherText[i] = (text[k]);
                    break;
                }
                else if (plaintext[i] >= 'A' && plaintext[i] <= 'Z')
                {
                    cipherText[i] = toupper(text[k]);
                    break;
                }
                else
                {
                    cipherText[i] = (text[k] + 32);
                    break;
                }
            }
        }
    }
    printf("ciphertext: %s\n", cipherText);
}

bool arrayStringControl(string text)
{
    bool c;
    for (int i = 0, a = strlen(text); i < a; i++)
    {

        if (isalpha(text[i]))
        {
            c = true;
        }
        else
        {
            c = false;
            return c;
        }
        int num = 0;
        for (int k = 0, b = strlen(text); k < b; k++)
        {
            if (text[i] == text[k])
            {
                num += 1;
            }
        }

        if (num == 2)
        {
            c = false;
            return c;
        }
    }
    return c;
}