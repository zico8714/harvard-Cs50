#include <stdio.h>
#include <cs50.h>

int main(void)
{    
    long num;
    long digit = 0;
    long i;
    long cc;
    long sum=0;
    int sum2 = 0;
    int sumT;
    do
    {
        num = get_long("Number: \n");
    } while (num < 1 || num > 5900000000000000);

    cc = num;

    for (i = cc; i > 0; i /= 100)
    {
    sum += i % 10;
    }

    while (cc > 0)
    {
        digit = ((cc / 10)% 10 * 2);
        if (digit > 9)
        sum2 += ((digit / 10) + (digit % 10));
        else
        sum2 += digit;
        cc /= 100;
    }

     sumT = sum + sum2;
     if(sumT % 10 != 0)
        printf("INVALID\n");
     
     if(sumT % 10 == 0)
     {
         if(num > 4000000000000 && num < 4999999999999)
             printf("VISA\n");
         else if(num > 4000000000000000 && num < 4999999999999999)
             printf("VISA\n");
         else if(num > 340000000000000 && num < 379999999999999)
            printf("AMEX\n");
        else if(num > 5100000000000000 && num < 5599999999999999)
            printf("MASTERCARD\n");
        else
            printf("INVALID\n");
     }
//American express -- 15 digits -- 34 / 37;
//Visa -- 13/16 digits -- 4;
//Master Card -- 16 dig -- 51/52/53/54/55;
}
