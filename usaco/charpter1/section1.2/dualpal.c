/*
ID: huajian2
LANG: C
TASK: dualpal
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void numtran(long num, int base, char *number)
{
	int i = 0;
	do {
		number[i] = '0' + num % base;
		num /= base;
		i++;
	} while (num > 0);
	number[i] = '\0';
}

bool is_pal(char *number)
{
	int len = strlen(number);
	int i;
	for (i = 0; i < len/2; i++) {
		if (number[i] != number[len-1-i])
			return false;
	}
	return true;
}

main () {
    FILE *fin  = fopen ("dualpal.in", "r");
    FILE *fout = fopen ("dualpal.out", "w");
    int n, base, npal;
    char number[33];
    long start, num;

    fscanf (fin, "%d %ld", &n, &start);
    num = start;
    while (n > 0) {
    	num++;
    	npal = 0;
    	for (base = 2; base <= 10; base++) {
    		numtran(num, base, number);
    		if (is_pal(number)) {
    			++npal;
    			if (npal > 1)
    				break;
    		}
    	}
    	if (npal > 1) {
    		n--;
    		fprintf(fout, "%ld\n", num);
    	}
    }
 
    exit (0);
}