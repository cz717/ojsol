/*
ID: huajian2
LANG: C
TASK: stamps
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

#define INFINITY 300
#define MAX_STAMP 50
#define MAXN 10000 + 5

int cnt[MAXN];

int cmp(const void *a, const void *b) {
	return *((int *) a) - *((int *) b);
}

main () {
    FILE *fin  = fopen ("stamps.in", "r");
    FILE *fout = fopen ("stamps.out", "w");

    int k, n;
    int stamp[MAX_STAMP];
    int i, j, c, s, end;
    int tcnt, lcnt;

    fscanf (fin, "%d %d", &k, &n);
    for (i = 0; i < n; i++)
    	fscanf (fin, "%d", &stamp[i]);


    qsort (stamp, n, sizeof(stamp[0]), cmp);
    end = stamp[n-1] * k + 1;


    cnt[0] = 0;
    for (c = 1; c <= end; c++) {
    	tcnt = INFINITY;
    	for (s = 0; c >= stamp[s] && s < n; s++) {
    			lcnt = cnt[(c - stamp[s]) % 10000];
    		if (tcnt > 1 + lcnt)
    			tcnt = 1 + lcnt;
    	}
    	cnt[c % 10000] = tcnt;
    	if (tcnt > k) {
    		fprintf(fout, "%d\n", c - 1);
    		break;
    	}
    }

    exit(0);
}
