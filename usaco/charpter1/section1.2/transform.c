/*
ID: huajian2
LANG: C
TASK: transform
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct point
{
	int x;
	int y;
} point;

/*
  transform
  a point(x, y) via these transform become :
  #1: 90 Degree Rotation:	(y, n-1-x)
  #2: 180 Degree Rotation:	(n-1-x, n-1-y)
  #3: 270 Degree Rotation:	(n-1-y, x)
  #4: Reflection:			(x, n-1-y)
  #5: Combination: #1 + #4:	(y, x)
                   #2 + #4:	(n-1-x, y)
                   #3 + #4:	(n-1-y, n-1-x)
  #6: No Change:			(x, y)

  so there are 8 conbinations.
  we use int comb to indicate.
*/
point
transform(point a, int n, int comb)
{
	point b;
	switch (comb) {
		break;
	case 1:
		b.x = a.y;
		b.y = n-1-a.x;
		break;
	case 2:
		b.x = n-1-a.x;
		b.y = n-1-a.y;
		break;
	case 3:
		b.x = n-1-a.y;
		b.y = a.x;
		break;
	case 4:
		b.x = a.x;
		b.y = n-1-a.y;
		break;
	case 5:
		b.x = a.y;
		b.y = a.x;
		break;
	case 6:
		b.x = n-1-a.x;
		b.y = a.y;
		break;
	case 7:
		b.x = n-1-a.y;
		b.y = n-1-a.x;
		break;
	case 8:
		b.x = a.x;
		b.y = a.y;
	}

	return b;
}

main () {

    FILE *fin  = fopen ("transform.in", "r");
    FILE *fout = fopen ("transform.out", "w");
    int n;
    char square1[10][10], square2[10][10];
    int i, j;
    int trans;
    bool success;
    point a, b;

    fscanf (fin, "%d\n", &n);
    for (i = 0; i < n; i++)
    	fscanf(fin, "%s\n", square1[i]);
    for (i = 0; i < n; i++)
    	fscanf(fin, "%s\n", square2[i]);

    for (trans = 1; trans <= 8; trans++) {
    	success = true;
    	for (i = 0; i < n; i++) {
    		for (j = 0; j < n; j++) {
    			a.x = i;
    			a.y = j;
    			b = transform( a, n, trans);
    			if (square1[i][j] != square2[b.x][b.y]) {
    				success = false;
    				break;
    			}
    		}
    		if (!success)
    			break;
    	}
    	if (success) {
    		if (trans <= 5)
    			fprintf (fout, "%d\n", trans);
    		else if (trans == 8)
    			fprintf (fout, "6\n");
    		else
    			fprintf (fout, "5\n");

    		break;
    	}
    }

    if (!success)
    	fprintf(fout, "7\n");

    exit (0);
}



