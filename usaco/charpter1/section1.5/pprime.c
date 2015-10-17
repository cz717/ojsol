/*
ID: huajian2
LANG: C
TASK: pprime
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

FILE *fin;
FILE *fout;
int a, b;
int min_len, max_len, len;
int i, j;
int palindrome[8];
int pal;

bool is_prime(int x)
{
    int i;
    int s = sqrt(x);
    for (i = 2; i <= s; i++)
        if (x%i == 0)
            return false;

    return true;
}

void gen_pal(int deep, int len)
{
    int half = (len-1)/2;
    int i, j;
    // printf("deep: %d len: %d half: %d\n", deep, len, half);
    if (deep == 0) {
        for (i = 1; i < 10; i+=2) {
            palindrome[deep] = i;
            palindrome[len - deep - 1] = i;
            if (deep >= half) {
                pal = 0;
                for (j = 0; j < len; j++) {
                    pal *= 10;
                    pal += palindrome[j];
                }
                // printf("pal: %d\n", pal);
                if (is_prime(pal) && pal >= a && pal < b)
                    fprintf(fout, "%d\n", pal);
            } else {
                gen_pal(deep+1, len);
            }
        }
    } else {
        for (i = 0; i < 10; i++) {
            palindrome[deep] = i;
            palindrome[len - deep - 1] = i;
            if (deep >= half) {
                pal = 0;
                for (j = 0; j < len; j++) {
                    pal *= 10;
                    pal += palindrome[j];
                }
                // printf("pal: %d \n", pal);
                if (pal > b)
                    break;
                else if ( pal >= a && is_prime(pal))
                    fprintf(fout, "%d\n", pal);

            } else {
                gen_pal(deep+1, len);
            }
        }
    }
}

main () {
    fin  = fopen ("pprime.in", "r");
    fout = fopen ("pprime.out", "w");
    fscanf (fin, "%d %d\n", &a, &b);


    i = a;
    j = b;
    for (min_len = 1; i/=10; min_len++);
    for (max_len = 1; j/=10; max_len++);

    for (len = min_len; len <= max_len; len++)
        gen_pal(0, len);
    

    exit (0);
}
