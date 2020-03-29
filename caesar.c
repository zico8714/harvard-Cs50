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

    int n = strlen(argv[1]);
    int check = 1;

    if(argc == 2)
    {
        for(int i = 0; i < n; i++)
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
                if(pt[i] + change > 90)
                {
                    int num = pt[i] - 91;
                    int final = (65 + change) + num;
                    printf("%c", final);
                }
                else
                {
                    printf("%c", pt[i] + change);
                }
            }
            else
            {
                if(pt[i] + change > 122)
                {
                    int num = pt[i] - 123;
                    int final = (97 + change) + num;
                    printf("%c", final);
                }
                else
                {
                    printf("%c", pt[i] + change);
                }

            }
        }
        else
        {

            printf("%c", pt[i]);

        }

    }
    }
    printf("\n");
    return 0;
}