/*
ID: huajian2
LANG: C
TASK: skidesign
*/
#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
     return ( *(int *)a - *(int *)b );
}

long cal_cost(int *hills, int n, int begin, int end)
{
	long cost = 0;
	int i;
	for (i = 0; hills[i] < begin; i++)
		cost += (begin - hills[i]) * (begin - hills[i]);
	for (i = n-1; hills[i] > end; i--)
		cost += (hills[i] - end) * (hills[i] - end);

	return cost;
}

main () {
    FILE *fin  = fopen ("skidesign.in", "r");
    FILE *fout = fopen ("skidesign.out", "w");
    int n, i;
    int hills[1000];
    int begin, end, len, scala;
    long cost, min_cost;


    fscanf (fin, "%d\n", &n);
    for (i = 0; i < n; i++)
    	fscanf (fin, "%d\n", &hills[i]);

    qsort(hills, n, sizeof(hills[0]), cmp);

    min_cost = 0;
    for (begin = hills[0], end = begin + 17; end <= hills[n-1]; ++begin, ++end) {
    	cost = cal_cost(hills, n, begin, end);
    	if (cost < min_cost || min_cost == 0)
    		min_cost = cost;
    }

    fprintf (fout, "%ld\n", min_cost);
    exit (0);
}
