/*
ID: huajian2
LANG: C
TASK: cowtour
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAXN 150
#define INFIN 200000

FILE *fout;

int n;
int x[MAXN];
int y[MAXN];
int adj[MAXN][MAXN];
double dis[MAXN][MAXN];
double max[MAXN];
int sub[MAXN];

double distant(int ax, int ay, int bx, int by) {
    double a = ax - bx;
    double b = ay - by;
    return sqrt(pow(a, 2) + pow(b, 2)); 
}

void set_sub(int p, int num) {
	int i;
	sub[p] = num;
	for (i = 0; i < n; i++) {
		if (adj[p][i] && !sub[i])
			set_sub(i, num); 
	}
}

void sp(int s) {
	int p[MAXN];
	int i, j, k, m;

	/* get all nodes belong to this subgraph */
	for (i = 0, m = 0; i < n; i++)
		if (sub[i] == s)
			p[m++] = i;

	/* initial */
	for (i = 0; i < m; i++)
		for (j = 0; j < m; j++) {
			if (adj[p[i]][p[j]])
				dis[p[i]][p[j]] = distant(x[p[i]], y[p[i]], x[p[j]], y[p[j]]);
			else 
				dis[p[i]][p[j]] = INFIN;
		}

	/* shortest path */
	for (k = 0; k < m; k++) {
		for (i = 0; i < m; i++) {
			for (j = 0; j < m; j++) {
				if (dis[p[i]][p[j]] > dis[p[i]][p[k]] + dis[p[k]][p[j]])
					dis[p[i]][p[j]] = dis[p[i]][p[k]] + dis[p[k]][p[j]];
			}
		}
	}

}

main () {
    FILE *fin  = fopen ("cowtour.in", "r");
    fout = fopen ("cowtour.out", "w");
    int i, j, r, s, d;

    fscanf (fin, "%d", &n);
    for (i = 0; i < n; i++)
    	fscanf (fin, "%d %d", &x[i], &y[i]);
    for (i = 0; i < n; i++)
    	for (j = 0; j < n; j++)
    		fscanf (fin, "%1d", &adj[i][j]);
    for (i = 0; i < n; i++)
        adj[i][i] = 1;

    /* find subgraph */
    memset(sub, 0, sizeof(sub));
    int subnum = 0;
    for (i = 0; i < n; i++) {
    	if (!sub[i])
    		set_sub(i, ++subnum);
    }

    /* shortest path */
    for (s = 1; s <= subnum; s++)
    	sp(s);


    double dia, min_dia = INFIN;
    /* connect subgraph 1 with 2, 3, ... , subnum */
    for (r = 1; r < subnum; r++) {
        for (s = r+1; s <= subnum; s++) {
        	int a, b;
        	double d, len = INFIN;
        	for (i = 0; i < n; i++) {
        		if (sub[i] == r) {
        			for (j = 0; j < n; j++) {
        				if (sub[j] == s) {
        					d = distant(x[i], y[i], x[j], y[j]);
        					if (len > max[i] + max[j] + d) {
        						a = i;
        						b = j;
        						len = max[i] + max[j] + d;
        					}
        				}
        			}
        		}
        	}  

            adj[a][b] = adj[b][a] = 1;
            dis[a][b] = dis[b][a] = distant(x[a], y[a], x[b], y[b]);
            for (i = 0; i < n; i++) {
                if (sub[i] == r) {
                    for (j = 0; j < n; j++) {
                        if (sub[j] == s)
                            dis[i][j] = dis[j][i] = dis[i][a] + dis[a][b] + dis[b][j];
                    }
                }
            }

            dia = 0;
            for (i = 0; i < n; i++) {
                if (sub[i] == r || sub[i] == s) {
                    for (j = 0; j < n; j++) {
                        if (sub[j] == r || sub[j] == s) {
                            if (dia < dis[i][j])
                                dia = dis[i][j];
                        }
                    }
                }
            }
            if (min_dia > dia)
                min_dia = dia;
        }
    }

    fprintf(fout, "%.6f\n", min_dia);

    exit (0);
}
