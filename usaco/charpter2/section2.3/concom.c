/*
ID: huajian2
LANG: C
TASK: concom
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

main () {
    FILE *fin  = fopen ("concom.in", "r");
    FILE *fout = fopen ("concom.out", "w");
    int n;
    int con[101][101];
    int stock[101][101];
    int indir[101][101];
    int i, j, p, cmp;
    bool done;

    for (i = 0; i < 101; i++) {
    	for (j = 0; j < 101; j++) {
    		con[i][j] = 0;
    		stock[i][j] = 0;
    		indir[i][j] = 0;
    	}
    }

    fscanf (fin, "%d", &n);
    while (n--) {
    	fscanf(fin, "%d %d %d", &i, &j, &p);
    	stock[i][j] = p;
    	indir[i][j] = p;
    }

    for (cmp = 1; cmp <= 100; cmp++) {
    	//printf("\n[ %d ]\n", cmp); ////
    	done = false;
    	while (!done) {
    		done = true;
    		for (i = 1; i <= 100; i++) {
    			if (stock[cmp][i] > 50 || indir[cmp][i] > 50) {
    				if (!con[cmp][i]) {
    					//printf("%d ", i); ///////////
    					done = false;
    					con[cmp][i] = 1;
    					for (j = 1; j <= 100; j++)
    						indir[cmp][j] += stock[i][j];
    					indir[cmp][cmp] = 0;
    				}
    			}
    		}
    	}
    }

    for (cmp = 1; cmp <= 100; cmp++)
    	for (i = 1; i <= 100; i++)
    		if (con[cmp][i] && i != cmp)
    			fprintf(fout, "%d %d\n", cmp, i);

    exit (0);
}