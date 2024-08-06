#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
    float l = 0, s = 0, w = 0, index;

    string text = get_string("Text: \n");
    int len = strlen(text);
    for (int i = 0; i <= len; i++)
    {
        if (toupper(text[i]) >= 'A' && toupper(text[i]) <= 'Z')
        {
            l++;
        }
        if ((text[i] == '.') || (text[i] == '?' && text[i + 1] != '"') || (text[i] == '!'))
        {
            s++;
        }
        if (isspace(text[i]) || text[i] == '\0')
        {
            w++;
        }
    }
    printf("L: %f\n S: %f\n W: %f\n", l, s, w);

    l = ((l / w) * 100);
    s = ((s / w) * 100);

    index = round((0.0588 * l - 0.296 * s - 15.8));

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 1 && index <= 16)
    {
        printf("Grade %i\n", (int)index);
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
}