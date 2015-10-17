/*
ID: huajian2
LANG: C
TASK: fact4
*/
#include <stdio.h>
#include <stdlib.h>

main () {
    FILE *fin  = fopen ("fact4.in", "r");
    FILE *fout = fopen ("fact4.out", "w");

    int n, f = 1, i;

    fscanf (fin, "%d", &n);

    for (i = 2; i <= n; i++){
    	f *= i;
    	while (f%10 == 0)
    		f /= 10;
    	f %= 10000;
    }

    fprintf(fout, "%d\n", f%10);

    exit(0);
}
