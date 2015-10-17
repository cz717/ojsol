/*
ID: huajian2
LANG: C
TASK: nocows
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int pedigree[201][101];

main () {
    FILE *fin  = fopen ("nocows.in", "r");
    FILE *fout = fopen ("nocows.out", "w");
    int n, k;
    int i, j, ln, rk;
    int temp1, temp2, sum;

    fscanf (fin, "%d %d", &n, &k);

    for (i = 0; i <= n; i++) {
    	for (j = 0; j <= k; j++) {
    		if (i == 0 || j == 0)
    			pedigree[i][j] == 0;
    		else if (j > i || i > pow(2, j)-1)
    			pedigree[i][j] = 0;
    		else if (i == 1)
    			pedigree[i][j] = 1;
    		else {
    			temp1 = 0;	/* both of children are k-1 high */
    			temp2 = 0;	/* one = k-1, one < k-1 */ 

    			for (ln = 1; ln < i-1; ln++)
    				temp1 += pedigree[ln][j-1] * pedigree[i-1-ln][j-1];
    			temp1 %= 9901;

    			for (ln = j-1; ln < i-1; ln++) {
                    sum = 0;
    				if (pedigree[ln][j-1]) {
    					for (rk = 1; rk < j-1; rk++)
    						sum += pedigree[i-1-ln][rk];
    					sum %= 9901;
                    }
    				temp2 += sum * pedigree[ln][j-1];
    			}
    			temp2 *= 2;
    			temp2 %= 9901;

    			pedigree[i][j] = (temp1 + temp2)%9901;
    		}
            //printf("pedigree[%d][%d] = %d\n", i, j, pedigree[i][j]); ///////
    	}
    }


    fprintf (fout, "%d\n", pedigree[n][k]);
    exit (0);
}
