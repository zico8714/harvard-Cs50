#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
//Include all the libraries

//functions
int count_letters(string texto);
int count_words(string texto);
int count_sentence(string texto);

int main(void)
{
    //Prompt for string
    string text = get_string("Text:\n");

    int letters = count_letters(text);

    int words = count_words(text);

    int sentences = count_sentence(text);
    //Get S and L
    float L = ((100 * (float) letters) / ((float) words + 1));

    float S = ((100 * (float) sentences) / ((float) words + 1));
    //Get index
    float index = 0.0588 * L - 0.296 * S - 15.8;
    //Round number
    int redon = round(index);
    //Text answered
    if (redon < 0)

        printf("Before Grade 1\n");

    else
    {

        switch(redon)
        {
            case 0:
                printf("Before Grade 1\n");
                break;
            case 1:
                printf("Before Grade 1\n");
                break;
            case 2:
                printf("Grade 2\n");
                break;
            case 3:
                printf("Grade 3\n");
                break;
            case 4:
                printf("Grade 4\n");
                break;
            case 5:
                printf("Grade 5\n");
                break;
            case 6:
                printf("Grade 6\n");
                break;
            case 7:
                printf("Grade 7\n");
                break;
            case 8:
                printf("Grade 8\n");
                break;
            case 9:
                printf("Grade 9\n");
                break;
            case 10:
                printf("Grade 10\n");
                break;
            case 11:
                printf("Grade 11\n");
                break;
            case 12:
                printf("Grade 12\n");
                break;
            case 13:
                printf("Grade 13\n");
                break;
            case 14:
                printf("Grade 14\n");
                break;
            case 15:
                printf("Grade 15\n");
                break;
            default:
                printf("Grade 16+\n");
        }
    }

}
//Every function
int count_letters(string texto)
{
    int wdsC = 0;
    for (int i = 0, n = strlen(texto); i < n; i++)
    {
        if(isalpha(texto[i]))
        {
            wdsC++;
        }
    }

        return wdsC;
}

int count_words(string texto)
{
    int lettC = 0;
    for (int i = 0, n = strlen(texto); i < n; i++)
    {
        if(isspace(texto[i]))
        {
            lettC++;
        }
    }
        return lettC;
}

int count_sentence(string texto)
{
    int sentC = 0;
    for (int i = 0, n = strlen(texto); i < n; i++)
    {
        if(texto[i] == 46 || texto[i] == 33 || texto[i] == 63)
        {
        sentC++;
        }
    }

        return sentC;
}