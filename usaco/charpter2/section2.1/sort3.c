/*
ID: huajian2
LANG: C
TASK: sort3
*/
#include <stdio.h>
#include <stdlib.h>

int min(int x, int y)
{
	return x>y?y:x;
}

main () {
    FILE *fin  = fopen ("sort3.in", "r");
    FILE *fout = fopen ("sort3.out", "w");
    int n, i, j;
    int num[1000];
    int count[4] = {0, 0, 0, 0};
    int start[4] = {0, 0, 0, 0};
    int end[4] = {0};
    int loc[4][4];
    int x, min_swap = 0;


    fscanf (fin, "%d\n", &n);
 	for (i = 0; i < n; i++) {
 		fscanf (fin, "%d\n", &num[i]);
 		count[num[i]]++;
 	}

 	start[2] = count[1];
 	start[3] = count[1] + count[2];
 	end[1] = start[2] - 1;
 	end[2] = start[3] - 1;
 	end[3] = n-1;

 	for (i = 0; i < 4; i++)
 		for (j = 0; j < 4; j++)
 			loc[i][j] = 0;

 	for (i = 1; i <= 3; i++) {
 		for (j = start[i]; j <= end[i]; j++) {
 			loc[i][ num[j] ] ++;
 		}
 	}

 	x = min(loc[1][3], loc[3][1]);
 	loc[1][3] -= x;
 	loc[3][1] -= x;
 	loc[1][1] += x;
 	loc[3][3] += x;
 	min_swap += x;

 	x = min(loc[1][2], loc[2][1]);
 	loc[1][2] -= x;
 	loc[2][1] -= x;
 	loc[1][1] += x;
 	loc[2][2] += x;
 	min_swap += x;

 	x = min(loc[2][3], loc[3][2]);
 	loc[2][3] -= x;
 	loc[3][2] -= x;
 	loc[2][2] += x;
 	loc[3][2] += x;
 	min_swap += x;

 	min_swap += (loc[1][2] + loc[1][3]) * 2;

 	fprintf(fout, "%d\n", min_swap);

    exit (0);
}
