/*
ID: huajian2
LANG: C
TASK: spin
*/
#include <stdio.h>
#include <stdlib.h>

#define ROUND 360

void rotate();
int is_align();

int speed[5];
int wedge_num[5];
int start[5][5];
int extent[5][5];
int degree[360];

int main() {
    FILE *fin  = fopen ("spin.in", "r");
    FILE *fout = fopen ("spin.out", "w");

    int i, j, cnt, align;

    for (i = 0; i < 5; i++) {
    	fscanf (fin, "%d %d", &speed[i], &wedge_num[i]);
    	for (j = 0; j < wedge_num[i]; j++)
    		fscanf (fin, "%d %d", &start[i][j], &extent[i][j]);
    }

    if (is_align()) {
    	fprintf(fout, "0\n");
    	exit(0);
    }
    
    align = 0;
    for (cnt = 1; cnt <= 360; cnt++) {
    	rotate();
    	////////////////////////////////////////////////
    	// printf("cnt: %d\n", cnt);
    	// for (i = 0; i < 5; i++) {
    	// 	printf("   ");
    	// 	for (j = 0; j < wedge_num[i]; j++)
    	// 		printf("(%d %d) ", start[i][j], start[i][j]+extent[i][j]);
    	// 	printf("\n");
    	// }
    	////////////////////////////////////////////////

    	if (is_align()) {
    		fprintf(fout, "%d\n", cnt);
    		align = 1;
    		break;
    	}
    }

    if (!align)
    	fprintf(fout, "none\n");

    exit(0);
}


void rotate() {
	int i, j;
	for (i = 0; i < 5; i++) {
		for (j = 0; j < wedge_num[i]; j++) {
			start[i][j] += speed[i];
			start[i][j] %= 360;
		}
	}
}

int is_align() {
	int i, j, d, end;
	int pass_all, pass_wheel;
	for (d = 0; d < 360; d++) {
		pass_all = 1;
		for (i = 0; i < 5; i++) {	/* for each wheel */
			pass_wheel = 0;
			for (j = 0; j < wedge_num[i]; j++) {
				end = (start[i][j] + extent[i][j]) % 360;
				if (d >= start[i][j] && d <= end
					|| end <= start[i][j] && (d >= start[i][j] || d <= end)) {
					pass_wheel = 1;
					break;
				}
			}
			if (!pass_wheel) {
				pass_all = 0;
				break;
			}
		}
		if (pass_all)
			return 1;
	}
	return 0;
}
