/*
ID: huajian2
LANG: C
TASK: sprime
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

FILE *fin;
FILE *fout;

bool is_prime(int x)
{
    int i;
    int s = sqrt(x);
    if (x == 1)
    	return false;
    for (i = 2; i <= s; i++)
        if (x%i == 0)
            return false;

    return true;
}

void dps(int number, int depth, int max_depth)
{
	int i, n;

	number *= 10;
	for (i = 1; i < 10; i++) {
		n = number + i;
		if (is_prime(n)) {
			if (depth == max_depth)
				fprintf(fout, "%d\n", n);
			else
				dps(n, depth+1, max_depth);
		}
	}
}

main () {
	fin  = fopen ("sprime.in", "r");
	fout = fopen ("sprime.out", "w");
    int n;

    fscanf (fin, "%d\n", &n);

    dps(0, 1, n);

    exit (0);
}
