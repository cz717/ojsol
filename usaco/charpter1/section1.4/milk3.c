/*
ID: huajian2
LANG: C
TASK: milk3
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int capacity[3];
int amount[3] = {0};
bool possible[21] = {false};
bool traveled[21][21][21] = {false};
bool first_time = true;

bool is_full(int i)
{
	return amount[i] == capacity[i]; 
}

void pour()
{
	int i, j;
	int a, b, c;

	// printf("[%d %d %d]\n", amount[0], amount[1], amount[2]);

	if (traveled[amount[0]][amount[2]][amount[3]])
		return;
	else
		traveled[amount[0]][amount[2]][amount[3]] = true;

	if (amount[0] == 0)
		possible[amount[2]] = true;

	for (i = 0; i < 3; i++) {
		if (amount[i] > 0) {
			for (j = 0; j < 3; j++) {
				if (j!=i && !is_full(j)) {
					a = amount[0];
					b = amount[1];
					c = amount[2];

					if ((amount[i]+amount[j]) <= capacity[j]) {
						amount[j] += amount[i];
						amount[i] = 0;
						pour(i, j);
					} else {
						amount[i] -= (capacity[j] - amount[j]);
						amount[j] = capacity[j];
						pour(i, j);
					}

					amount[0] = a;
					amount[1] = b;
					amount[2] = c;
				}
			}
		}
	}
}

main () {
    FILE *fin  = fopen ("milk3.in", "r");
    FILE *fout = fopen ("milk3.out", "w");
	int i;

    fscanf (fin, "%d %d %d\n", &capacity[0], &capacity[1], &capacity[2]);
    amount[2] = capacity[2];

    pour();

    for (i = 0; i < capacity[2]; i++)
    	if (possible[i])
    		fprintf(fout, "%d ", i);
    fprintf(fout, "%d\n", capacity[2]);


    exit (0);
}
