/*
ID: huajian2
LANG: C
TASK: humble
*/
#include <stdio.h>
#include <stdlib.h>

#define MAXN 100000

int cmp(const void *a, const void *b) {
	return *((int *) a) - *((int *) b);
}

main () {
    FILE *fin  = fopen ("humble.in", "r");
    FILE *fout = fopen ("humble.out", "w");

    int k, n;
    long num[MAXN]; 
    int prime[100];
    int point[100];
    long mul[100];
    int i, nxt, pt, cnt;

    fscanf (fin, "%d %d", &k, &n);
    for (i = 0; i < k; i++)
    	fscanf (fin, "%d", &prime[i]);

    qsort (prime, k, sizeof(prime[0]), cmp);

    num[0] = 1;
    for (i = 0; i < k; i++) {
        point[i] = 0;
        mul[i] = prime[i];
    }

    for (cnt = 1; cnt <= n; cnt++) {
        nxt = mul[0];
        pt = 0;
        for (i = 1; i < k; i++) {
            if (nxt > mul[i]) {
                nxt = mul[i];
                pt = i;
            }
        }
        num[cnt % MAXN] = nxt;
        for (i = 0; i < k; i++) {
            if (mul[i] == nxt) {
                ++point[i];
                mul[i] = prime[i] * num[point[i] % MAXN];
            }
        }
    }

    fprintf(fout, "%ld\n", num[n % MAXN]);

    exit(0);
}
