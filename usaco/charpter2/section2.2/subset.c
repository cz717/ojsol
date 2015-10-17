/*
ID: huajian2
LANG: C
TASK: subset
*/
#include <stdio.h>
#include <stdlib.h>

int n;
int sum, start, i;
unsigned int ablity[40][391];	/* ablity[start][target] */




main () {
    FILE *fin  = fopen ("subset.in", "r");
    FILE *fout = fopen ("subset.out", "w");

    fscanf (fin, "%d", &n);

    sum = n * (n+1) / 2;
    if (sum % 2 == 1) {
    	fprintf(fout, "0\n");
    	exit(0);
    }

    sum /= 2;
    ablity[n][0] = 1;
    ablity[n][n] = 1;
    for (start = n-1; start >= 0; start--) {
    	for (i = 0; i <= sum; i++) {
    		ablity[start][i] = ablity[start+1][i];
    	}
    	for (i = sum; i >= 0; i--)
    		ablity[start][i+start] += ablity[start][i];
    }
    fprintf(fout, "%u\n", ablity[1][sum]/2);


    exit (0);
}