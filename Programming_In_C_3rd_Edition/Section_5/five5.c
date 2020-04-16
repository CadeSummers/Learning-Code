#include <stdio.h>

/* take the below and retype it more executable and readable

#include <stdio.h>
int main(void){
int n,two_to_the_n;
printf("TABLE OF POWERS OF TWO\n\n");
printf(" n 2 to the n\n");
printf("--- ---------------\n");
two_to_the_n=1;
for(n=0;n<=10;++n){
printf("%2i %i\n",n,two_to_the_n); two_to_the_n*=2;}
return 0;} 

*/

int main()
{
    int n, tn; // number, two to the power n
    
    printf("\t TABLE OF POWERS OF 2\n");
    printf("\n");
    printf("\tn\t\t");
    printf(" 2^n\t\n");
    printf("_________________________________________\n");
    
    n = 1;
    tn = 2;
    
    while (n <= 10)
    {
        printf("\t%i\t\t", n);
        printf(" %i\t\n", tn);
        n++;
        tn*= 2;
    }
    
}



