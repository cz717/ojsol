/*
ID: huajian2
LANG: C
TASK: beads
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

main () {
	char beads[700];
	int n, i;

    FILE *fin  = fopen ("beads.in", "r");
    FILE *fout = fopen ("beads.out", "w");

    fscanf (fin, "%d\n", &n);
    fscanf (fin, "%s", beads);
    for (i = 0; i < n; i++)
    	beads[n+i] = beads[i];
 
 	int this_begin = 0;
 	int next_begin, next_next_begin;
 	char color = 'w';
 	int this_length, max_length = 0;
 	bool first = true;

 	for (i = 0; i < n; i++) {
 		if (beads[i] != 'w') {
 			if (color == 'w') {
 				color = beads[i];
 				next_begin = i;
 			} else if (beads[i] == color) {
 				next_begin = i;
 			} else {
 				color = beads[i];
 				break;
 			}
 		}
 	}
 	if (i == n) {
 		fprintf(fout, "%d\n", n);
 		exit(0);
 	}


 	for (; i < n * 2; i++) {
 		if (beads[i] != 'w') {
 			if (beads[i] == color)
 				next_next_begin = i;
 			else {
 				if (first) {
 					first = false;
 					if (i >= n) {
 						fprintf(fout, "%d\n", n);
 						exit(0);
 					}
 				}
 				
 				this_length = i - this_begin;
 				if (this_length > max_length)
 					max_length = this_length;
 				color = beads[i];
 				this_begin = ++next_begin;
 				next_begin = next_next_begin;
 				next_next_begin = i;
 			}
 		}
 	}
 	this_length = i - this_begin;
 	if (this_length > max_length)
 		max_length = this_length;

    fprintf(fout, "%d\n", max_length);
    exit (0);
}

