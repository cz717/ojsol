/*
ID: huajian2
LANG: C
TASK: hamming
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

FILE *fin;
FILE *fout;
int n, b, d;
unsigned char code[65];


int ham_dis(unsigned char a, unsigned char b)
{
	unsigned char c = a ^ b;
	int distance = 0;

	while (c > 0) {
		distance += c % 2;
		c /= 2;
	}
	return distance;
}

bool find(int deep, unsigned last)
{
	unsigned int ui;
	unsigned char this;
	bool ok;
	int i, j;

	if (deep == 1)
		ui = 0;
	else
		ui = last + 1;

	for (; ui < 256; ui++) {
		this = (unsigned char) ui;

		ok = true;
		for (i = 1; i < deep; i++) {
			if (ham_dis(this, code[i]) < d) {
				ok = false;
				break;
			}
		}

		if (ok) {
			code[deep] = this;

			if (deep == n) {
				for (j = 1; j <= n; j++) {
					fprintf(fout, "%d", code[j]);
					if (j == n || j%10 == 0)
						fprintf(fout, "\n");
					else
						fprintf(fout, " ");
				}
				return true;
			} else {
				if (find(deep+1, this))
					return true;
			}
		}
	}

	return false;
}


main () {
    fin  = fopen ("hamming.in", "r");
    fout = fopen ("hamming.out", "w");
    
    fscanf (fin, "%d %d %d", &n, &b, &d);
    find(1, 0);

    exit (0);
}