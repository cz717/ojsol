/*
ID: huajian2
LANG: C
TASK: ttwo
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char grid[12][12];
int path[10][10][4][10][10][4];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

typedef struct sit
{
	int x;	/* position */
	int y;
	int d;	/* direction: 0 - north, 1 - east, 2 - south, 3 - west */
}sit;

#define sit_equal(a, b) (a.x == b.x && a.y == b.y && a.d == b.d)

sit next(sit c)
{
	sit n = c;
    n.x += dx[c.d];
    n.y += dy[c.d];
	return n;
}

main () {
    FILE *fin  = fopen ("ttwo.in", "r");
    FILE *fout = fopen ("ttwo.out", "w");

    int i, j;
    sit fc, cc;	/* curruent */
    sit n;
    int count;

    for (i = 1; i < 11; i++)
    	fscanf (fin, "%s", grid[i]+1);

    for (i = 0; i < 12; i++) {
    	grid[0][i] = '*';
    	grid[11][i] = '*';
    	grid[i][0] = '*';
    	grid[i][11] = '*';
    }

    for (i = 1; i < 11; i++)
    	for (j = 1; j < 11; j++) {
    		if (grid[i][j] == 'F') {
    			fc.x = i; fc.y = j;
    		} else if (grid[i][j] == 'C') {
    			cc.x = i; cc.y = j;
    		}
    	}
    fc.d = 0; cc.d = 0;

    memset(path, 0, sizeof(path));

    count = 0;
    while (1) {
    	/* if meet */
    	if (fc.x == cc.x && fc.y == cc.y) {
    		fprintf(fout, "%d\n", count);
    		exit(0);
    	}

    	if (path[fc.x-1][fc.y-1][fc.d][cc.x-1][cc.y-1][cc.d]) {
    		fprintf(fout, "0\n");
    		exit(0);
    	} else {
            path[fc.x-1][fc.y-1][fc.d][cc.x-1][cc.y-1][cc.d] = 1;
        }

    	n = next(fc);
    	if (grid[n.x][n.y] == '*')
    		fc.d = (fc.d + 1) % 4;	/* rotate */
    	else
    		fc = n;

    	n = next(cc);
    	if (grid[n.x][n.y] == '*')
    		cc.d = (cc.d + 1) % 4;
    	else
    		cc = n;
    	
    	++count;
    }

}
