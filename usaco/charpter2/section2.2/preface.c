/*
ID: huajian2
LANG: C
TASK: preface
*/
#include <stdio.h>
#include <stdlib.h>

/* I V X L C D M */
int count[7];
char roman[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};

void foo(int place, int num)
{
	int base = place * 2;
	if (num < 4)
		count[base] += num;
	else if (num == 4) {
		count[base]++;
		count[base + 1]++;
	} else if (num < 9) {
		count[base] += num%5;
		count[base + 1]++;
	} else if (num == 9) {
		count[base]++;
		count[base + 2]++;
	}
}

main () {
    FILE *fin  = fopen ("preface.in", "r");
    FILE *fout = fopen ("preface.out", "w");
    int n, i, j, number, last;
    fscanf (fin, "%d", &n);

    for (i = 1; i <= n; i++) {
    	number = i;
    	for (j = 0; j < 4; j++) {
    		foo(j, number%10);
    		number /= 10;
    	}
    }

    for (last = 6; last >= 0; last--)
    	if (count[last] > 0)
    		break;

    for (i = 0; i <= last; i++)
    	fprintf(fout, "%c %d\n", roman[i], count[i]);

    exit (0);
}