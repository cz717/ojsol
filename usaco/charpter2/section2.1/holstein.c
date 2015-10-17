/*
ID: huajian2
LANG: C
TASK: holstein
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

FILE *fin;
FILE *fout;
int v, g;
int requirement[25];
int fedtype[15][25];
int types[15];
int total[25];

bool enough(int type_num)
{
	int i, j, t;

	for (i = 0; i < v; i++)
		total[i] = 0;

	for (i = 0; i < type_num; i++) {
		t = types[i];
		for (j = 0; j < v; j++)
			total[j] += fedtype[t][j];
	}

	for (i = 0; i < v; i++)
		if (total[i] < requirement[i])
			return false;

	return true;
}


bool test(int type_num, int deep, int last)
{
	int i, j;
	printf("test(%d %d %d)...\n", type_num, deep, last); /////////
	for (i = last+1; i < g; i++) {
		types[deep] = i;
		if (deep == type_num - 1) {
			if (enough(type_num)) {
				fprintf (fout, "%d", type_num);
				for (j = 0; j < type_num; j++)
					fprintf(fout, " %d", types[j]+1);
				fprintf(fout, "\n");
				return true;
			}
		} else {
			if(test(type_num, deep+1, i))
				return true;
		}
	}

	return false;
}


main()
{
	fin  = fopen ("holstein.in", "r");
	fout = fopen ("holstein.out", "w");
	int i, j, type_num;

    fscanf (fin, "%d\n", &v);
    for (i = 0; i < v; i++)
    	fscanf (fin, "%d", &requirement[i]);

    fscanf (fin, "%d\n", &g);
    for (i = 0; i < g; i++) {
    	for (j = 0; j < v; j++)
    		fscanf (fin, "%d", &fedtype[i][j]);
    }

    printf("test...\n"); //////////////////////////////
    for (type_num = 1; type_num <= g; type_num++)
    	if(test(type_num, 0, -1))
    		break;

    exit(0);
}