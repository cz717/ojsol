/*
ID: huajian2
LANG: C
TASK: agrinet
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

#define MAXN 100
#define INFINI 20000000

main () {
    FILE *fin  = fopen ("agrinet.in", "r");
    FILE *fout = fopen ("agrinet.out", "w");

    int n;
    int matrix[MAXN][MAXN];
    int intree[MAXN];
    int dis[MAXN];
    int tree_size, tree_cost;
    int i, j;
    int node, cost;

    fscanf (fin, "%d", &n);
    for (i = 0; i < n; i++)
    	for (j = 0; j < n; j++)
    		fscanf (fin, "%d", &matrix[i][j]);

    memset(intree, 0, sizeof(intree));
    memset(dis, 0xFF, sizeof(dis));

    intree[0] = 1;
    tree_size = 1;
    tree_cost = 0;
    for (i = 0; i < n; i++)
    	dis[i] = matrix[0][i];

    while (tree_size < n) {
    	cost = INFINI;
    	for (i = 0; i < n; i++) {
    		if (!intree[i] && cost > dis[i]) {
    			node = i;
    			cost = dis[i];
    		}
    	}

    	intree[node] = 1;
    	++tree_size;
    	tree_cost += cost;
    	for (i = 0; i < n; i++) {
    		if (!intree[i] && dis[i] > matrix[node][i])
    			dis[i] = matrix[node][i];
    	}
    }


    fprintf (fout, "%d\n", tree_cost);

    exit (0);
}
