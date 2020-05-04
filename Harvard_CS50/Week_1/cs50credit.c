#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main()
{
    int sumodd, sumeven, i, check, check2; 
    long cardodd, cardeven;
    
    long pow1, pow2, pow3, pow4;
    pow1 = pow(10, 15);
    pow2 = pow(10, 14);
    pow3 = pow(10, 13);
    pow4 = pow(10, 12);
    
    long card = get_long("Enter your card number: ");

    sumodd = sumeven = 0;
    cardeven = cardodd = card;
    
    cardeven /= 10; 
    
    while (cardeven > 0) 
    {
        i = ((cardeven % 100) % 10); 
        i *= 2;
        if (i > 9)
        {
            i = (i / 10) + (i % 10); 
        }
        sumeven = sumeven + i;
        cardeven = cardeven / 100;
    }
    while (cardodd > 0)
    {
        sumodd = sumodd + ((cardodd % 100) % 10); 
        cardodd = cardodd / 100;
    }
    
    if ((card / pow4 < 1))
    {
        printf("INVALID\n");
    }
    else if (((sumodd + sumeven) % 10) == 0)
    {
        printf("VALID\n");
    }
    else
    {
        printf("INVALID\n");
    }
    
    check = (card / pow1);
    check2 = (card / pow2);
    
    if (check == 4 || card / pow4 == 4)
    {
        printf("VISA\n");
    }
    else if ((card / pow3) == 34 || (card / pow3) == 37)
    {
        printf("AMEX\n");
    }
    else if (check2 > 50 && check2 < 56)
    {
        printf("MASTERCARD\n");
    }
}
