#include <stdio.h>
#include <cs50.h>

void pyramid(int n) {
    int null_space, i, blocks;
    null_space = n;
    i = (n-n);
    blocks = (n-n);

    for (; i < n;)
        {
            i++;
            for (; null_space > (n-n); null_space -= 1)
                {
                    printf(" ");
                }
            null_space = n - i;
            blocks += null_space;
            for (; blocks < n; blocks += 1)
                {
                    printf("#");
                }
            printf("  ");
            blocks -= null_space;
            for (; blocks > (n-n); blocks --)
                {
                    printf("#");
                }
            printf(" \n");
            blocks = (n-n);
        }
}

int main(void){
    int n;
    do {
        n = get_int("height: ");
    } while (n <= 0 || n >= 9);
    pyramid(n);




}

