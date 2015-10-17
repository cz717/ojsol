/*
ID: huajian2
LANG: C
TASK: ariprog
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

long bisquares[32000];
bool isbq[126002];

main () {
    FILE *fin  = fopen ("ariprog.in", "r");
    FILE *fout = fopen ("ariprog.out", "w");
    int N, M;
    long i, j, first, bq;
    int bqnum, max_dif, dif;
    bool ok;

    fscanf (fin, "%d %d", &N, &M);

    for (i = 0; i <= M; i++)  {
    	for (j = 0; j <= M; j++) {
    		isbq[i*i + j*j] = true;
    	}
    }
    for (i = 0, j = 0; i <= 126002; i++)
    	if (isbq[i])
    		bisquares[j++] = i;
    bqnum = j;

    // printf("%d bisquares: \n", bqnum);
    // for (i = 0; i < bqnum; i++)
    // 	printf("%ld ", bisquares[i]);
    // printf("\n");

    max_dif = bisquares[bqnum-1] / (N-1) + 1;
    // printf("max_dif %d\n", max_dif);

    bool none = true;
    for (dif = 1; dif <= max_dif; dif++) {
    	for (first = 0; first < bqnum; first++) {
    		bq = bisquares[first];
    		if (bq + dif*(N-1) > bisquares[bqnum-1])
    			break;
    		
    		ok = true;
    		for (j = 1; j < N; j++) {
    			if (!isbq[bq + dif*j]) {
    				ok = false;
    				break;
    			}
    		}
    		if (ok) {
    			none = false;
    			fprintf(fout, "%ld %d\n", bq, dif);
    		}
    	}
    }
    if (none)
    	fprintf(fout, "NONE\n");

    exit (0);
}