/*
ID: huajian2
LANG: C
TASK: numtri
*/
#include <stdio.h>
#include <stdlib.h>
main () {
    FILE *fin  = fopen ("numtri.in", "r");
    FILE *fout = fopen ("numtri.out", "w");
    unsigned  R, len, max, i;
    unsigned int a[1002] = {0, 0};
    unsigned int b[1002] = {0, 0};
    unsigned int *this, *last;

    fscanf (fin, "%d\n", &R);
    for (len = 1; len <= R; len++) {
    	if (len%2) {
    		this = a;
    		last = b;
    	} else {
    		this = b;
    		last = a;
    	}

    	for (i = 1; i <= len; i++) {
    		fscanf(fin, "%d ", &this[i]);
    		this[i] += last[i-1]>last[i]? last[i-1]:last[i];
    	}
    	this[len+1] = 0;
    }

    max = 0;
    for (i = 1; i <= R; i++)
    	if (this[i]>max)
    		max = this[i];

    fprintf (fout, "%d\n", max);
    exit (0);
}