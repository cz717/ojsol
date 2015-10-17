/*
ID: huajian2
LANG: C
TASK: barn1
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX_STALL 200
#define MAX_COW 200

int cmp ( const void *a , const void *b )
{
	return *(int *)a - *(int *)b;
}

main () {
    FILE *fin  = fopen ("barn1.in", "r");
    FILE *fout = fopen ("barn1.out", "w");
    int M, S, C;
    int blank[MAX_STALL] = {0};
    int cows[MAX_COW] = {0};
    int begin, scale, i, stall, last_stall;

    fscanf (fin, "%d %d %d\n", &M, &S, &C);
    for (i = 0; i < C; i++)
    	fscanf(fin, "%d\n", &cows[i]);

    qsort(cows, C, sizeof(cows[0]), cmp);

    begin = cows[0];
    scale = cows[C-1] - cows[0] + 1;
    for (i = 1; i < C; i++) {
    	blank[cows[i] - cows[i-1] - 1]++;
    }


    M--;
    for (i = S-1; i >= 0 && M > 0; i--) {
    	if (blank[i]) {
    		if (blank[i] > M) {
    			scale -= i * M;
    			M = 0;
    		} else {
    			scale -= i * blank[i];
    			M -= blank[i];
    		}
    	}
    }

    fprintf (fout, "%d\n", scale);
    exit (0);
}