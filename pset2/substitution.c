#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
//Include needed libraries

int main(int argc, string argv[])
{
    //decalre ints
    int count = 0;
    //check validity
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
        //stops if more or less than 2 args
    }
    else
    {
        //checks each digit to be a letter

        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            if (isdigit(argv[1][i]))
            {
                printf("Usage: ./substitution key\n");
                return 1;
            }
            else
            {
                count++;
            }

            int h = 0;

            for (int j = 0; j < n; j++)
            {
                int asd = tolower(argv[1][j]);
                int qwe = tolower(argv[1][i]);

            if (asd == qwe)
            {
                h++;
            }

            if (h > 1)
            {
                printf("Letters should not be repeated.\n");
                return 1;
            }
            //asd
            }

        }


    }
    //asdasd

    //checks quantity of letters
    if (count != 26)
    {
        printf("The key should have a length of 26.\n");
        return 1;
    }

    printf("plaintext: ");

    string plt = get_string("");

    printf("ciphertext: ");



    for (int i = 0, n = strlen(plt); i < n; i++)
    {
        //asd
        if (isalpha(plt[i]))
        {
            int nuev[26];
            int h;
            for (int j = 0; j < 26; j++)
            {
                nuev[j] = argv[1][j];
                if (nuev[j] == plt[i])
                {
                h = nuev[j];
                }
            }
            if (islower(plt[i]))
            {

                int f = plt[i] - 97;
                printf("%c", tolower(nuev[f]));

            }
            //asdasd
            else
            {
                int f = plt[i] - 65;
                printf("%c", toupper(nuev[f]));

            }
        }
        else
        {
            printf("%c", plt[i]);
        }
    }
    //asd
    printf("\n");
    return 0;
}