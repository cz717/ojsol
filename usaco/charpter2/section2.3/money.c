/*
ID: huajian2
LANG: C
TASK: money
*/
#include <stdio.h>
#include <stdlib.h>

int coin[25];
long long way[10001];

main () {
    FILE *fin  = fopen ("money.in", "r");
    FILE *fout = fopen ("money.out", "w");
    int v, n;
    int value, i, j;

    fscanf (fin, "%d %d", &v, &n);
    for (i = 0; i < v; i++)
    	fscanf(fin, "%d", &coin[i]);
    //printf("v %d  n %d\n", v, n);

    for (i = 0; i <= n; i++)
    	way[i] = 0;

    for (i = 0; i < v; i++) {
    	value = coin[i];
    	for (j = 1; j+value <= n; j++)
    		way[j + value] += way[j];
    	for (j = value; j <= n; j += value)
    		++way[j];
    }

    fprintf (fout, "%lld\n", way[n]);
    exit (0);
}