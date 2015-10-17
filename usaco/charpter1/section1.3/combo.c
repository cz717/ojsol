/*
ID: huajian2
LANG: C
TASK: combo
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool foo(int i, int comb, int n)
{
	return ((i == (comb+n-1)%n)
		     || i == (comb+n-2)%n
		     || i == comb%n
		     || i == (comb+1)%n
		     || i == (comb+2)%n);
}

bool is_close(int i, int j, int k, int *comb, int n)
{
	return (foo(i, comb[0], n) && foo(j, comb[1], n) && foo(k, comb[2], n)); 
}

main () {
    FILE *fin  = fopen ("combo.in", "r");
    FILE *fout = fopen ("combo.out", "w");
    int n, count = 0;
    int john[3];
    int master[3];
    int i, j, k;

    fscanf (fin, "%d\n", &n);
    for (i = 0; i < 3; i++)
    	fscanf (fin, "%d", &john[i]);
    for (i = 0; i < 3; i++)
    	fscanf (fin, "%d", &master[i]);


    for (i = 0; i < n; i++) {
    	for (j = 0; j < n; j++) {
    		for (k = 0; k < n; k++) {
    			if (is_close(i, j, k, john, n) || is_close(i, j, k, master, n)) {
    			//	printf("%d,%d,%d\n", i+1, j+1, k+1);
    				count++;
    			}
    		}
    	}
    }

    fprintf (fout, "%d\n", count);
    exit (0);
}
