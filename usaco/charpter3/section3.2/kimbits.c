/*
ID: huajian2
LANG: C
TASK: kimbits
*/
#include <stdio.h>
#include <stdlib.h>


main () {
    FILE *fin  = fopen ("kimbits.in", "r");
    FILE *fout = fopen ("kimbits.out", "w");

    int bits[32];
    unsigned int c[32][32];		/* combonation */
    unsigned int sum[32][32];	/* sum[m][n] = sum{ c[m][i] } (i=0~n)  */
    int n, limit;
    unsigned int l;
    int i, j;

    fscanf (fin, "%d %d %u", &n, &limit, &l);
    printf("l: %u\n", l);


    for (i = 0; i < 32; i++)
    	bits[i] = 0;
    /* c(j, i) */
    for (j = 0; j < 32; j++) {
    	for (i = 0; i < 32; i++) {
    		if (i == 0)
    			c[j][i] = 1;
            else if (j == 0)
                c[j][i] = 0;
    		else
    			c[j][i] = c[j-1][i-1] + c[j-1][i];
    	}
    }

    for (j = 0; j < 32; j++) {
        for (i = 0; i < 32; i++) {
    		if (i == 0)
    			sum[j][i] = c[j][i];
    		else
    			sum[j][i] = sum[j][i-1] + c[j][i];
    	}
    }

    ///////////////////////////////
    for (j = 1; j < 32; j++) {
    	for (i = 1; i < 32; i++)
    		printf("%u ", c[j][i]);
    	printf("\n");
    }
    printf("\n");	
    for (j = 1; j < 32; j++) {
    	for (i = 1; i < 32; i++)
    		printf("%u ", sum[j][i]);
    	printf("\n");
    }

    unsigned int cnt = 0;
    while (l > 1 && cnt < limit) {
        printf("l: %d, cnt: %d\n", l, cnt); ////////////////
    	for (i = 1; i <= n; i++) {
	    	if (sum[i][limit-cnt] >= l) {
	    		bits[i] = 1;
	    		l -= sum[i-1][limit-cnt];
	    		++cnt;
                printf("  bits[%d] = 1\n", i); //////////
	    		break;
	    	}
    	}
    }

    for (i = n; i > 0; i--)
    	fprintf(fout, "%d", bits[i]);
    fprintf(fout, "\n");

    exit(0);
}
