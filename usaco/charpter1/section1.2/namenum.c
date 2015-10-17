/*
ID: huajian2
LANG: C
TASK: namenum
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

FILE *fout, *dict;
char number[13];
char name[13];
char validname[13];
bool none = true;
void find (int x, int n);

main () {
    FILE *fin  = fopen ("namenum.in", "r");
    fout = fopen ("namenum.out", "w");
    dict = fopen ("dict.txt", "r");
    int length;


    fscanf (fin, "%s\n", number);
    length = strlen(number);
    name[length] = '\0';

    find(0, length-1);
    if (none)
    	fprintf(fout, "NONE\n");


    exit (0);
}

void find (int x, int n)
{
	char num = number[x];
	char c[4] = {'\0'};
	int i, cmp;
	if (num < '7') {
		for (i = 0; i < 3; i++)
			c[i] = 'A' + (num - '2') * 3 + i;
	}
	if (num == '7') {
		c[0] = 'P';
		c[1] = 'R';
		c[2] = 'S';
	}
	if (num > '7') {
		for (i = 0; i < 3; i++)
			c[i] = 'T' + (num - '8') * 3 + i;
	}

	for (i = 0; i < 3; i++) {
		name[x] = c[i];
		if (x < n)
			find (x+1, n);
		else {
		//	printf("%s\n", name); /////////////////
			cmp = strcmp(name, validname);
			if (!cmp) {
				none = false;
				fprintf(fout, "%s\n", name);
				continue;
			}
			if (cmp < 0)
				continue;

			while (1) {
				fscanf (dict, "%s\n", validname);
			//	printf("    %s\n", validname); ///////////////
				cmp = strcmp(name, validname);
				if (!cmp) {
					none = false;
					fprintf(fout, "%s\n", name);
					break;
				}
				if (cmp < 0)
					break;
			}
		}
	}
}

