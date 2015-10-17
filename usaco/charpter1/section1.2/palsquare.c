/*
ID: huajian2
LANG: C
TASK: palsquare
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool is_palindromic(long num, int base)
{
	int n[24];
	int len = 0, i;
	do {
		n[len] = num % base;
		num /= base;
		len++;
	} while (num != 0);

	for (i = 0; i < len/2; i++)
		if (n[i] != n[len-1-i])
			return false;
	return true;
}

main () {
    FILE *fin  = fopen ("palsquare.in", "r");
    FILE *fout = fopen ("palsquare.out", "w");
    int base;
    long num, square, j;
    int n[9], s[24];
    int nlen, slen, i;
    bool is_palindromic;

    fscanf (fin, "%d\n", &base);

    for (j = 1; j <= 300; j++) {
    	num = j;
    	square = num * num;
    	
    	/* is palindromic? */
    	is_palindromic = true;
    	slen = 0;
    	do {
			s[slen] = square % base;
			square /= base;
			slen++;
		} while (square != 0);

		for (i = 0; i < slen/2; i++) {
			if (s[i] != s[slen-1-i]) {
				is_palindromic = false;
				break;
			}
		}

		/* print */
		if (is_palindromic) {
			nlen = 0;
			do {
				n[nlen] = num % base;
				num /= base;
				nlen++;
			} while (num != 0);

			for (i = nlen-1; i >= 0; i--) {
				if (n[i] < 10)
					fprintf(fout, "%d", n[i]);
				else
					fprintf(fout, "%c", 'A'+(n[i]-10));
			}

			fprintf(fout, " ");

			for (i = 0; i < slen; i++){
				if (s[i] < 10)
					fprintf(fout, "%d", s[i]);
				else
					fprintf(fout, "%c", 'A'+(s[i]-10));	
			}

			fprintf(fout, "\n");
		}
    }

    exit (0);
}
