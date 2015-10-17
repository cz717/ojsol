/*
ID: huajian2
LANG: C
TASK: inflate
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

#define MAXN 10005

main () {
    FILE *fin  = fopen ("inflate.in", "r");
    FILE *fout = fopen ("inflate.out", "w");

    int point[MAXN];
    int minute[MAXN];
    int max[MAXN];
    int con_time, pro_cate;
    int i, j, t;

    fscanf (fin, "%d %d", &con_time, &pro_cate);
    for (i = 0; i < pro_cate; i++)
    	fscanf (fin, "%d %d", &point[i], &minute[i]);


    max[0] = 0;
    for (t = 1; t <= con_time; t++) {
    	max[t] = 0;
    	for (j = 0; j < pro_cate; j++) {
    		if (t - minute[j] >= 0 && max[t] < point[j] + max[t-minute[j]])
    			max[t] = point[j] + max[t-minute[j]];
    	}
    }

    fprintf(fout, "%d\n", max[con_time]);
    
    exit(0);
}
