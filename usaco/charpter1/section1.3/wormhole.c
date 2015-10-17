/*
ID: huajian2
LANG: C
TASK: wormhole
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int count;

typedef struct point
{
	long x;
	long y;		
} point;

int cmp(const void *a, const void *b)
{
	point *c = (point *)a;
	point *d = (point *)b;
	if (c->y == d->y)
		return c->x - d->x;
	else
		return c->y - d->y;
}


bool test(point *wh, int *pair, int n, int x, int first)
{
	if (x == n-1 || wh[x+1].y != wh[x].y)
		return false;
	else if (wh[x+1].y == wh[first].y && wh[x+1].x == wh[first].x)
		return true;
	else
		return test(wh, pair, n, pair[x+1], first);
}

bool is_cycle(point *wh, int *pair, int n)
{
	//return true;
	int i;
	for (i = 0; i < n; i++) {
		if (test(wh, pair, n, pair[i], i)) {
		//	printf(" (%d) ", i);
			return true;
		}
	}
	return false;

}



void combo(int last, int x, int n, point *wh, int *pair)
{
	int i, j;
	for (i = last+1; i < n; i++) {
		if (pair[i] == -1) {
			for (j = i+1; j < n; j++) {
				if (pair[j] == -1) {
					pair[i] = j;
					pair[j] = i;
					printf("[%d %d] ", i, j); /////////////
					if (x == n/2 -1) {
						if (is_cycle(wh, pair, n)) {
							printf(" ---cycle");
							count++;
						}
						printf("\n");
					} else {
						combo(i, x+1, n, wh, pair);
					}
					pair[i] = -1;
					pair[j] = -1;
				}
			}
		}
	}
}


main () {
    FILE *fin  = fopen ("wormhole.in", "r");
    FILE *fout = fopen ("wormhole.out", "w");
    int n, i;
    point wormhole[12];
    int pair[12];

    fscanf (fin, "%d\n", &n);
    for (i = 0; i < n; i++)
    	fscanf (fin, "%ld %ld\n", &(wormhole[i].x), &(wormhole[i].y) );

    qsort(wormhole, n, sizeof(wormhole[0]), cmp);
    for (i = 0; i < n; i++)
    	printf("%d - %ld %ld\n", i, wormhole[i].x, wormhole[i].y);

//    printf("combo...\n"); //////////////
    for (i = 0; i < 12; i++)
    	pair[i] = -1;
    count = 0;
    combo(-1, 0, n, wormhole, pair);

    fprintf (fout, "%d\n", count);
    exit (0);
}
