#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main()
{
    int sumodd, sumeven, i, check, check2; //sum of odd and even places, integer (to check size of numbers), card type check 1 & 2
    long cardodd, cardeven; //odd and even places in card 1st (ones) places, 3rd (hundreds) place... etc.
    
    long pow1, pow2, pow3;
    pow1 = pow(10, 15);
    pow2 = pow(10, 14);
    pow3 = pow(10, 12);
    
    long card = get_long("Enter your card number: ");

    sumodd = sumeven = 0;
    cardeven = cardodd = card;
    
    cardeven /= 10; // see line 19
    
    while (cardeven > 0) //combined multiply every other digit and grabbing ever other digit into one step
    {
        i = ((cardeven % 100) % 10); // this operation grabs every other digit. I divided by 10 to offset where I grab by one to grabs 10s, 1000s, etc. rather than 1, 100 etc.
        i *= 2;
        if (i > 9)
        {
            i = (i / 10) + (i % 10); // works because i can never be larger than 2 digits.
        }
        sumeven = sumeven + i;
        cardeven = cardeven/100;
    }
    while (cardodd > 0)
    {
        sumodd = sumodd + ((cardodd % 100) % 10); //once again, this function grabs every other digit, starting in ones place
        cardodd = cardodd/100;
    }
    
    if (((sumodd + sumeven) % 10) == 0) 
    {
        printf("Valid Card\n");
    }
    else
    {
        printf("Invalid Card\n");
    }
    
    check = (card / pow1);
    check2 = (card / pow2);
    
    if (check == 4 || card / pow3 == 4)
    {
        printf("VISA\n");
    }
    else if (check == 3 && (check2 == 4 || check2 == 7))
    {
        printf("AMEX\n");
    }
    else if (check == 5 && (check2 > 0 && check2 < 6))
    {
        printf("MasterCard\n");
    }
    else
    {
        printf("Card type unknown.\n");
    }
}
