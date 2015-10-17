/*
ID: huajian2
LANG: C
TASK: butter
*/
#include <stdio.h>
#include <stdlib.h>

#define INFINIT 300000
#define MAXN 800

int c, p, e;
int pasture[MAXN];
int total_dis[MAXN];
int dis[MAXN][MAXN];


int main() {
    FILE *fin  = fopen ("butter.in", "r");
    FILE *fout = fopen ("butter.out", "w");

    int i, j, k;
    int a, b, d;
    int min;

    /* initial */
    for (i = 0; i < 800; i++) {
    	pasture[i] = 0;
    	total_dis[i] = 0;
    }
    for (i = 0; i < 800; i++)
    	for (j = 0; j < 800; j++)
    		dis[i][j] = INFINIT;

    /* read */
    fscanf (fin, "%d %d %d", &c, &p, &e);
    for (i = 0; i < c; i++) {
    	fscanf (fin, "%d", &a);
    	++pasture[a-1];
    }
    for (i = 0; i < e; i++) {
    	fscanf (fin, "%d %d %d", &a, &b, &d);
    	--a; --b;
    	dis[a][b] = dis[b][a] = d;
    }


    /* shortest path */
    for (k = 0; k < p; k++)
    	for (i = 0; i < p; i++)
    		for (j = i+1; j < p; j++)
    			if (dis[i][j] > dis[i][k] + dis[k][j])
    				dis[i][j] = dis[j][i] = dis[i][k] + dis[k][j];


    /* total path */
    for (i = 0; i < p; i++)
    	for (j = 0; j < p; j++)
            if (i != j)
    		  total_dis[i] += dis[i][j] * pasture[j];

    min = total_dis[0];
    for (i = 0; i < p; i++)
    	if (min > total_dis[i])
    		min = total_dis[i];

    fprintf(fout, "%d\n", min);
    exit(0);
}
