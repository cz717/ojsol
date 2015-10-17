/*
ID: huajian2
LANG: C
TASK: crypt1
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool foo(int x, bool *num)
{
	do {
		if (!num[x%10])
			return false;
		x /= 10;
	} while (x > 0);

	return true;
}


main () {
    FILE *fin  = fopen ("crypt1.in", "r");
    FILE *fout = fopen ("crypt1.out", "w");
    int n, i, j;
    int par1, par2, product;
    bool num[10] = {false};
    int count = 0;

    fscanf (fin, "%d\n", &n);
    for (i = 0; i < n; i++) {
    	fscanf (fin, "%d", &j);
    	num[j] = true;
    }

    for (i = 100; i < 1000; i++) {
    	for (j = 10; j < 100; j++) {
            par1 = i * (j % 10);
            par2 = i * (j / 10);
    		product = i * j;
    		if (foo(i, num) && foo(j, num)
                && foo(par1, num) && par1 < 1000
                && foo(par2, num) && par2 < 1000
                && foo(product, num) && product < 10000) 
            {
                //printf("%d * %d = %d\n", i, j, product);
    			count++;
            }
    	}
    }

    fprintf (fout, "%d\n", count);
    exit (0);
}
