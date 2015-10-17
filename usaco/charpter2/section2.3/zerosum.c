/*
ID: huajian2
LANG: C++
TASK: zerosum
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

FILE *fin;
FILE *fout;
int n;
char expr[18];
char op[3] = {' ', '+', '-'};

void check(void)
{
	int num[2];		/* operand stack */
	char o = 'o';	/* operator */
	int sp = 0;		/* number of operand in stack */

	char c;
	int a, b, i;

	for (i = 0; i <= 2*(n-1); i++) {
		c = expr[i];
		if (isdigit(c))
			num[sp++] = c - '0';
		else if (c == ' ') {
			b = expr[++i] - '0';
			a = num[sp-1];
			num[sp-1] = a * 10 + b;
		} else {
			switch (o) {
			case '+':
				num[0] += num[1];
				sp = 1;
				break;
			case '-':
				num[0] -= num[1];
				sp = 1;
				break;
			case 'o':
				break;
			}
			o = c;
		}
	}
	if (o == '+')
		num[0] += num[1];
	else
		num[0] -= num[1];

	if (num[0] == 0)
		fprintf(fout, "%s\n", expr);
}

void search(int deep)
{
	int i;
	for (i = 0; i < 3; i++) {
		expr[deep] = op[i];
		if (deep == 2*n-3) {
			check();
		} else
			search(deep+2);
	}
}

main () {
    fin  = fopen ("zerosum.in", "r");
    fout = fopen ("zerosum.out", "w");
    int i;

    fscanf (fin, "%d", &n);
    for (i = 0; i < 9; i++ )
    	expr[2*i] = '1' + i;
    expr[2*n-1] = '\0';

    search(1);

    exit (0);
}
