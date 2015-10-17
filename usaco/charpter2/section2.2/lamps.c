/*
ID: huajian2
LANG: C
TASK: lamps
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/*
  a button being pushed k times is equal to being pushed k%2 times,
  so there are only 2 situations for each button: pushed 0 or 1 time.
  for button [1, 2, 3], push 2 of them are equal to push the other 1.
  for c > 4, there are at least 1 button be pushed more than 1 time,
  so we only consider c = 0 ~ 4.
  we can enumerate all combinations:
  1. push 0 button
  2. push 1 button
      [1]
      [2]
      [3]
      [4]
  3. push 2 unique buttons
      [1][2] = [3]
      [1][3] = [2]
      [1][4]
      [2][3] = [1]
      [2][4]
      [3][4]
  4. push 3 unique buttons
      [2][3][4] = [1][4]
      [1][3][4] = [2][4]
      [1][2][4] = [3][4]
      [1][2][3] = 0
  5. push all buttons
      [1][2][3][4] = [4]
  so there are only 8 possible configurations.
*/ 

FILE *fin;
FILE *fout;
int n, c, lamp;
int on[101];
int off[101];
int configuration[10][101];
int conf = 0;
int comb[8][4] = {
	{0, 0, 0, 0},
	{1, 0, 0, 0},
	{0, 1, 0, 0},
	{0, 0, 1, 0},
	{0, 0, 0, 1},
	{1, 0, 0, 1},
	{0, 1, 0, 1},
	{0, 0, 1, 1},
};

int choose[5][10] = {
	{1, 0, 0, 0, 0, 0, 0, 0},
	{0, 1, 1, 1, 1, 0, 0, 0},
	{1, 1, 1, 1, 0, 1, 1, 1},
	{1, 1, 1, 1, 0, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 1}
};

int *p[10];

void push_button(int b, int *lamps)
{
	int i;
	switch (b) {
	case 0:
		for(i = 1; i <= n; i++)
			lamps[i] = lamps[i]? 0 : 1;
		break;
	case 1:
		for (i = 1; i <= n; i+=2)
			lamps[i] = lamps[i]? 0 : 1;
		break;
	case 2:
		for (i = 2; i <= n; i+=2)
			lamps[i] = lamps[i]? 0 : 1;
		break;
	case 3:
		for (i = 1; i <= n; i+=3)
			lamps[i] = lamps[i]? 0 : 1;
		break;
	}
}

int comp(const void *a, const void *b)
{
	int **l1 = (int **) a;
	int **l2 = (int **) b;
	int i;
	for (i = 1; i <= n; i++) {
		if ((*l1)[i] > (*l2)[i])
			return 1;
		if ((*l1)[i] < (*l2)[i])
			return -1;
	}
	return 0;
}

bool check(int *lamps)
{
	int i;
	for (i = 1; on[i] != -1; i++)
		if (lamps[on[i]] == 0)
			return false;
	for (i = 1; off[i] != -1; i++)
		if (lamps[off[i]] == 1)
			return false;
	return true;
}

main () {
    fin  = fopen ("lamps.in", "r");
    fout = fopen ("lamps.out", "w");
    int i, j;

    fscanf (fin, "%d\n%d\n", &n, &c);
    for (i = 1; on[i-1] != -1; i++)
    	fscanf (fin, "%d", &on[i]);
    for (i = 1; off[i-1] != -1; i++)
    	fscanf (fin, "%d", &off[i]);

    if (c > 4)
    	c = c%2?3:4;
    printf("c: %d\n", c); /////////

    for (i = 0; i < 10; i++)
    	for (j = 0; j < 101; j++)
    		configuration[i][j] = 1;

    conf = 0;
    for (i = 0; i < 8; i++) {
    	if (choose[c][i]) {
    		for (j = 0; j < 4; j++) {
    			if (comb[i][j])
    				push_button(j, configuration[conf]);
    		}
    		conf++;
    	}
    }
    printf("conf: %d\n", conf); ///////////

    for (i = 0; i < conf; i++)
    	p[i] = configuration[i];
    qsort(p, conf, sizeof(p[0]), comp);

    bool impossible = true;
    for (i = 0; i < conf; i++) {
    	if (check(p[i])) {
    		impossible = false;
    		for (j = 1; j <= n; j++)
    			fprintf(fout, "%d", p[i][j]);
    		fprintf(fout, "\n");
    	}
    }
    if (impossible)
    	fprintf(fout, "IMPOSSIBLE\n");


    exit (0);
}
