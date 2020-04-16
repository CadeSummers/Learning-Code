#include <stdio.h>
#include <cs50.h>
#include <math.h>

void credit(long i);

int main(void)
{
    long n2 = get_long ("Enter your credit card number: ");
    credit(n2);
}

void credit (long n2)
{

// option 1: convert long to string and identify numbers within
// option 2: create float for different variables, and isolate desired terms 1 by 1, then implement in code

    long z = floor(log10(n2)); // number of zeroes

    // dividing n by each 10 the pow z to isolate numbers in each place up to hundred billion
    // going to take each number and apply luhn algorithm
    int z1 = z; // storing this number to check for valid card length.
    z = z - 4; // I initially built this code around a 12-digit numerical code. Then I remembered cards have 6 digits. Yikes.
    long n = n2; // storing this number for future operations
    long qdril = floor(n/(pow (10, (z+4))));
    n = n - (qdril * (pow(10, (z+4))));
    long hun_tril = floor(n/(pow (10, (z+3))));
    n = n - (hun_tril * (pow(10, (z+3))));
    long ten_tril = floor(n/ pow(10, (z+2)));
    n = n - (ten_tril * (pow(10, (z+2))));
    long tril = floor(n/ pow(10, (z+1)));
    n = n - (tril *(pow(10, (z+1))));
    long hun_bil = floor(n/(pow (10, z)));
    n = n - (hun_bil * (pow(10, z)));
    long ten_bil = floor(n/(pow (10, (z-1))));
    n = n - (ten_bil * (pow(10, (z-1))));
    long bil = floor(n/(pow (10, (z-2))));
    n = n - (bil * (pow (10, (z-2))));
    long hun_mil = floor(n/(pow (10, (z-3))));
    n = n - (hun_mil * (pow (10, (z-3))));
    long ten_mil = floor(n/(pow (10, (z-4))));
    n = n - (ten_mil * (pow (10, (z-4))));
    long mil = floor(n/(pow (10, (z-5))));
    n = n - (mil * (pow (10, (z-5))));
    long hun_thous = floor(n/(pow (10, (z-6))));
    n = n - (hun_thous * (pow (10, (z-6))));
    long ten_thous = floor(n/(pow (10, (z-7))));
    n = n - (ten_thous * (pow(10, (z-7))));
    long thous = floor(n/(pow (10, (z-8))));
    n = n - (thous* (pow(10, (z-8))));
    long huns = floor(n/(pow (10, (z-9))));
    n = n - (huns *(pow(10, (z-9))));
    long tens = floor(n/(pow (10, (z-10))));
    n = n - (tens * (pow(10, (z-10))));
    long ones = floor (n / (pow (10, (z-11))));
    n = n - (ones * (pow (10, (z-11))));

// Variables successfully isolated w/ code above!!!
int cc1 = qdril; // checks 1st digit of card
int cc2 = hun_tril; // checks 2nd digit of card

tens *= 2;
thous *= 2;
hun_thous *= 2;
ten_mil *= 2;
bil *= 2;
hun_bil *= 2;
ten_tril *= 2;
qdril *= 2;

    if (tens > 9) // no single digit number can sum high enough such that code would need to repeat to get product isolate. If need be, change if to for.
    {
        int tens_z = floor(log10(tens));
        int tens_1 = floor(tens/(pow (10, tens_z)));
        tens = tens - (tens_1 * (pow(10, tens_z)));
        int tens_2 = floor(tens/(pow (10, (tens_z-1))));
        tens = tens - (tens_2 * (pow(10, (tens_z-1))));
        tens = tens_1 + tens_2;
    }
    if (thous > 9)
    {
        int thous_z = floor(log10(thous));
        int thous_1 = floor(thous/(pow (10, thous_z)));
        thous = thous - (thous_1 * (pow(10, thous_z)));
        int thous_2 = floor(thous/(pow (10, (thous_z-1))));
        thous = thous - (thous_2 * (pow(10, (thous_z-1))));
        thous = thous_1 + thous_2;
    }
    if (hun_thous > 9)
    {
        int hun_thous_z = floor(log10(hun_thous));
        int hun_thous_1 = floor(hun_thous/(pow (10, hun_thous_z)));
        hun_thous = hun_thous - (hun_thous_1 * (pow(10, hun_thous_z)));
        int hun_thous_2 = floor(hun_thous/(pow (10, (hun_thous_z-1))));
        hun_thous = hun_thous - (hun_thous_2 * (pow(10, (hun_thous_z-1))));
        hun_thous = hun_thous_1 + hun_thous_2;
    }
    if (ten_mil > 9)
    {
        int tmil_z = floor(log10(ten_mil));
        int tmil_1 = floor(ten_mil/(pow (10, tmil_z)));
        ten_mil = ten_mil - (tmil_1 * (pow(10, tmil_z)));
        int tmil_2 = floor(ten_mil/(pow (10, (tmil_z-1))));
        ten_mil = ten_mil - (tmil_2 * (pow(10, (tmil_z-1))));
        ten_mil = tmil_1 + tmil_2;

    }
    if (bil > 9)
    { 
        int bil_z = floor(log10(bil));
        int bil_1 = floor(bil/(pow (10, bil_z)));
        bil = bil - (bil_1 * (pow(10, bil_z)));
        int bil_2 = floor(bil/(pow (10, (bil_z-1))));
        bil = bil - (bil_2 * (pow(10, (bil_z-1))));
        bil = bil_1 + bil_2;

    }
    if (hun_bil > 9)
    {
        int hun_bil_z = floor(log10(hun_bil));
        int hun_bil_1 = floor(hun_bil/(pow (10, hun_bil_z)));
        hun_bil = hun_bil - (hun_bil_1 * (pow(10, hun_bil_z)));
        int hun_bil_2 = floor(hun_bil/(pow (10, (hun_bil_z-1))));
        hun_bil = hun_bil - (hun_bil_2 * (pow(10, (hun_bil_z-1))));
        hun_bil = hun_bil_1 + hun_bil_2;
    }
    if (ten_tril > 9)
    {
        int ten_tril_z = floor(log10(ten_tril));
        int ten_tril_1 = floor(ten_tril/(pow (10, ten_tril_z)));
        ten_tril = ten_tril - (ten_tril_1 * (pow(10, ten_tril_z)));
        int ten_tril_2 = floor(ten_tril/(pow (10, (ten_tril_z-1))));
        ten_tril = ten_tril - (ten_tril_2 * (pow(10, (ten_tril_z-1))));
        ten_tril = ten_tril_1 + ten_tril_2;
    }
    if (qdril > 9)
    {
        int qdril_z = floor(log10(qdril));
        int qdril_1 = floor(qdril/(pow (10, qdril_z)));
        qdril = qdril - (qdril_1 * (pow(10, qdril_z)));
        int qdril_2 = floor(qdril/(pow (10, (qdril_z-1))));
        qdril = qdril - (qdril_2 * (pow(10, (qdril_z-1))));
        qdril = qdril_1 + qdril_2;

    }

// Second check phase complete!!!

int val_check1 = (tens + thous + hun_thous + ten_mil + bil + hun_bil + ten_tril + qdril);

int val_check2 = (val_check1 + ones + huns + ten_thous + mil + hun_mil + ten_bil + tril + hun_tril); //sum of of product variables and remaining non-multiplied variables in n

// Final returns statement on card validity
if (val_check2 % 10 == 0 && z1 == 15)
{
    printf("Valid Card. \n");
    if (cc1 == 3 && cc2 == (4 | 7))
    {
        printf("AMEX. \n");
    }
    else if (cc1 == 4)
    {
        printf("VISA. \n");
    }
    else if (cc1 == 5 && (cc2 > 5 && cc2 != 0))
    {
        printf("Mastercard. \n");
    }
    else
    {
        printf("Unknown Card Type. \n");
    }
}
else
{
    printf("Invalid Card. \n");
}
//messy, messy, messy code. Could have been optimized with counters and loops. 
}
