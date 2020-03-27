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

int main (void)
{
    string text = get_string("Text:\n");

    int letters = count_letters(text);

    int words = count_words(text);

    int sentences = count_sentence(text);

    float L = ((100 * (float) letters) / ((float) words + 1));

    float S = ((100 * (float) sentences) / ((float) words + 1));

    float index = 0.0588 * L - 0.296 * S - 15.8;
    int redon = round(index);

    switch(redon)
    {
        case 0:
            printf("Before Grade 1");
        break;
        case 1:
            printf("Before Grade 1");
        break;
        case 2:
            printf("Grade 2");
        break;
        case 3:
            printf("Grade 3");
        break;
        case 4:
            printf("Grade 4");
        break;
        case 5:
            printf("Grade 5");
        break;
        case 6:
            printf("Grade 6");
        break;
        case 7:
            printf("Grade 7");
        break;
        case 8:
            printf("Grade 8");
        break;
        case 9:
            printf("Grade 9");
        break;
        case 10:
            printf("Grade 10");
        break;
        case 11:
            printf("Grade 11");
        break;
        case 12:
            printf("Grade 12");
        break;
        case 13:
            printf("Grade 13");
        break;
        case 14:
            printf("Grade 14");
        break;
        case 15:
            printf("Grade 15");
        break;
        default:
            printf("Grade 16+");
    }

}

int count_letters(string texto)
{
    int wdsC=0;
    for(int i = 0, n = strlen(texto); i < n; i++)
        {
            if(isalpha(texto[i]))
            wdsC++;
        }
    return wdsC;
}

int count_words(string texto)
{
    int lettC=0;
    for(int i = 0, n = strlen(texto); i < n; i++)
        {
            if(isspace(texto[i]))
            lettC++;
        }
    return lettC;
}

int count_sentence(string texto)
{
    int sentC=0;
    for(int i = 0, n = strlen(texto); i < n; i++)
        {
            if(texto[i] == 46 || texto[i] == 33 || texto[i] == 63)
            sentC++;
        }
    return sentC;
}