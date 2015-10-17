/*
ID: huajian2
LANG: C
TASK: frac1
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct fraction
{
	int numerator;
	int denominator;
} fraction;

int frac_cmp(const void *a, const void *b)
{
	fraction *x = (fraction *) a;
	fraction *y = (fraction *) b;
	return x->numerator * y->denominator - x->denominator * y->numerator;
}

int gcd(x, y)   /* x is bigger than y */
{
    int z = x%y;
    if (z == 0)
        return y;
    else
        return gcd(y, z);
}

main()
{
	FILE *fin  = fopen ("frac1.in", "r");
    FILE *fout = fopen ("frac1.out", "w");
    int n, i;
    int den, num;
    fraction frac[10000];
    int fra_num = 0;

    fscanf (fin, "%d", &n);
    for (den = 2; den <= n; den++) {
    	for (num = 1; num < den; num++) {
    		if (num == 1 || gcd(den, num) == 1) {
    			frac[fra_num].numerator = num;
    			frac[fra_num].denominator = den;
    			fra_num++;
    		}
    	}
    }

    qsort(frac, fra_num, sizeof(frac[0]), frac_cmp);
    fprintf(fout, "0/1\n");
    for (i = 0; i < fra_num; i++)
    	fprintf(fout, "%d/%d\n", frac[i].numerator, frac[i].denominator);
    fprintf(fout, "1/1\n");

}