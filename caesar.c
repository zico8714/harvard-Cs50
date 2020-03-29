#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if(argc == 1)
    {

        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {

    int check = 1;

    if(argc == 2)
    {
        for(int i = 0; i < argc; i++)
        {
            if(isdigit(argv[1][i]))
            {
            check = 0;
            }
            else
            {
            check++;
            }
        }
    }

        int change = atoi(argv[1]);

    if(check != 0)
    {

        printf("Usage: ./caesar key\n");

    }
    else
    {

        printf("plaintext: ");

    }

    string pt = get_string("");

    printf("ciphertext: ");




    for (int i = 0,a = strlen(pt); i < a; i++)
    {
        if(isalpha(pt[i]))
        {
            if(isupper(pt[i]))
            {
                int c = (pt[i] + change) % 26;
                printf("%i", c);
            }
            else
            {
                int c = (pt[i] + change) % 26;
                printf("%i\n", c);
            }
        }
        else
        {

            printf("%i\n", pt[i]);

        }

    }
    }
    printf("\n");
    return 0;
}