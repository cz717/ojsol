/*
ID: huajian2
LANG: C
TASK: ratios
*/
#include <stdio.h>
#include <stdlib.h>

int ratio[5][3];

int det(int a, int b, int c) {
	int det = 0;
	int i;
	for (i = 0; i < 3; i++) {
		det += ratio[a][i] * ratio[b][(i+1)%3] * ratio[c][(i+2)%3];
		det -= ratio[a][i] * ratio[b][(i+2)%3] * ratio[c][(i+1)%3];
	}
	return det;
}

int gcd(int a, int b) {
    if (a < b)
        return gcd(b, a);
    else if (b == 0)
        return a;
    else
        return gcd(b, a%b);
}

int sign(int x) {
    if (x > 0)
        return 1;
    else
        return -1;
}

main () {
    FILE *fin  = fopen ("ratios.in", "r");
    FILE *fout = fopen ("ratios.out", "w");

    int mult, d;
    int i, j;

    for (i = 0; i < 4; i++)
    	for (j = 0; j < 3; j++)
    		fscanf (fin, "%d", &ratio[i][j]);

    ratio[5][0] = det(0, 2, 3);
    ratio[5][1] = det(1, 0, 3);
    ratio[5][2] = det(1, 2, 0);
    mult = det(1, 2, 3);

    int s = sign(mult);
    for (i = 0; i < 3; i++) {
        if (ratio[5][i] == 0)
            continue;
        if (sign(ratio[5][i]) != s) {
            fprintf(fout, "NONE\n" );
            exit(0);
        }
        ratio[5][i] *= s;
    }
    mult *= s;

    d = mult;
    for (i = 0; i < 3; i++)
        if (ratio[5][i])
            d = gcd(d, ratio[5][i]);

    for (i = 0; i < 3; i++)
    	fprintf(fout, "%d ", ratio[5][i]/d);
    fprintf(fout, "%d\n", mult/d);
    exit(0);
}
