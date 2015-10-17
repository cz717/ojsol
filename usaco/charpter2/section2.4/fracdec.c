/*
ID: huajian2
LANG: C
TASK: fracdec
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXN 100000
int rem[MAXN], quo[MAXN];
int visited[MAXN][10];

int intleng(int x) {
	int l = 0;
	do {
		++l;
		x /= 10;
	} while (x);
	return l;
}

main(void)
{
    FILE *fin  = fopen ("fracdec.in", "r");
    FILE *fout = fopen ("fracdec.out", "w");	
	int n, d;
	int remaind, quotient, cnt, i, j, nl;
	int start, end, circul = 0;

	fscanf (fin, "%d %d", &n, &d);

	quotient = n / d;
	remaind = n % d;
	quo[0] = quotient;
	rem[0] = remaind;
	cnt = 1;

	for(i = 0; i < MAXN; i++)
		for (j = 0; j < 10; j++)
			visited[i][j] = 0;

	while(rem[cnt-1] && !circul) {
		remaind = rem[cnt-1] * 10;
		quo[cnt] = remaind / d;
		rem[cnt] = remaind % d;

		if (visited[rem[cnt]][quo[cnt]]) {
			start = visited[rem[cnt]][quo[cnt]];
			end = cnt;
			circul = 1;
			break;
		} else {
			visited[rem[cnt]][quo[cnt]] = cnt;
		}

		// printf("%d [%d %d %d]\n", cnt, quo[cnt], rem[cnt], circul);
		++cnt;
	}

	fprintf(fout, "%d.", quo[0]);
	nl = intleng(quo[0]);
	if (rem[0] == 0) {				/* integer */
		fprintf(fout, "0\n");
		exit(0);
	}
	if (circul) {
		for (i = 1; i < start; i++) {
			if (nl == 75)	fprintf(fout, "\n");
			nl = (nl + 1) % 76;
			fprintf(fout, "%d", quo[i]);
		}

		fprintf(fout, "(");
		if (nl == 75)	fprintf(fout, "\n");
		nl = (nl + 1) % 76;

		for (i = start; i < end; i++) {
			if (nl == 75)	fprintf(fout, "\n");
			nl = (nl + 1) % 76;
			fprintf(fout, "%d", quo[i]);
		}
		fprintf(fout, ")\n");
	} else {
		for (i = 1; i < cnt; i++) {
			if (nl == 75)	fprintf(fout, "\n");
			nl = (nl + 1) % 76;
			fprintf(fout, "%d", quo[i]);
		}
		fprintf(fout, "\n");
	}


	exit(0);
}
