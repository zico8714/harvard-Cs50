#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    int change;

    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        for (int i = 0; i < argc; i++)
        {
            if (isalpha(argv[1][i]))
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }

        change = atoi(argv[1]);
    }

    printf("plaintext: ");

    string plt = get_string("");

    for (int i = 0, n = strlen(plt); i < n; i++)
        {
            if (isalpha(plt[i]))
            {
                if (islower(plt[i]))
                {
                    int low = ((plt[i] - 97) + change) % 26;
                    int res = low + 97;
                    printf("%c", res);

                }
                else
                {
                    int upp = ((plt[i] - 65) + change) % 26;
                    int res = upp + 65;
                    printf("%c", res);
                }
            }
            else
            {
                printf("%c", plt[i]);
            }
        }
    return 0;
}