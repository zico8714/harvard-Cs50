#include <stdio.h>
#include <cs50.h>
//includes math.h
#include <math.h>
//starts
int main(void)
{
    int coins = 0;
    float o = 0.0;

    
    //Prompt user to get float
    do
    {
        o = get_float("What do I owe you?\n");      
    }
    while (o < 0);
    
    int Round = round(o * 100);
    do
    {
        //loop starts
        if (Round >= 25)
        {
            Round -= 25;
            coins++;
        }
        else if (Round >= 10)
        {
            Round -= 10;
            coins++;
        }
        else if (Round >= 5)
        {
            Round -= 5;
            coins++;
        }
        else
        {
            Round -= 1;
            coins++;
        }
    }
    while (Round > 0);
    //prints solution
    printf("%i\n", coins);
}
