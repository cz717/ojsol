/*
ID: huajian2
LANG: C
TASK: comehome
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define infinity 60000

int getid(char c) {
    if (islower(c))
        return c - 'a';
    else
        return 26 + c - 'A';
}

main () {
    FILE *fin  = fopen ("comehome.in", "r");
    FILE *fout = fopen ("comehome.out", "w");

    char *convert = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int graph[52][52];
    int dis[52];
    int parent[52];
    int visited[52];

    int p, d;
    char s[20];
    char a, b;
    int pas, min, node, i, j;

    for (i = 0; i < 52; i++) {
        dis[i] = infinity;
        visited[i] = 0;
        parent[i] = -1;
        for (j = 0; j < 52; j++)
            graph[i][j] = infinity;
    }

    fscanf (fin, "%d\n", &p);
    while (p--) {
    	fgets (s, 20, fin);
    	sscanf (s, "%c %c %d", &a, &b, &d);
    	i = getid(a);
        j = getid(b);
        if (d < graph[i][j]) {
            graph[i][j] = d;
            graph[j][i] = d;
        }
    }


    dis[51] = 0;
    pas = 0;
    
    while (pas < 52) {
    	min = infinity;
    	for (i = 0; i < 52; i++)
    		if (!visited[i] && dis[i] < min) {
    			min = dis[i];
    			node = i;
    		}

    	visited[node] = 1;
    	++pas;
    	for (i = 0; i < 52; i++) {
    		if (!visited[i]) {
    			if (dis[i] > dis[node] + graph[node][i] ) {
    				dis[i] = dis[node] + graph[node][i];
    				parent[i] = node;
    			}
    		}
    	}
    }

    min = infinity;
    for (i = 26; i < 51; i++) {
    	if (dis[i] < min) {
    		min = dis[i];
    		node = i;
    	}
    }
    fprintf(fout, "%c %d\n", convert[node], min);

    exit (0);
}
