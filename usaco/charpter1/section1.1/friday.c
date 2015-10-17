/*
ID: huajian2
LANG: C
TASK: friday
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool is_run(int year);
int month_length(int month, int year);

main () {
    FILE *fin  = fopen ("friday.in", "r");
    FILE *fout = fopen ("friday.out", "w");
    int count[7] = {0};
    int n;
    int year = 1899, month = 0, length;
    int remaind = 3;
    int i;

    fscanf(fin, "%d", &n);
    for (i = 0; i < n * 12; i++) {

        length = month_length(month, year);
        remaind = (remaind + length) % 7;
        ++count[remaind];

        month = (month+1) % 12;
        if (month == 1)
            ++year;
    }

    fprintf(fout, "%d ", count[6]);
    for (i = 0; i < 5; i++)
    	fprintf(fout, "%d ", count[i]);
    fprintf(fout, "%d\n", count[5]);

    exit(0);

}

bool is_run(int year)
{
	if (year%100 == 0)
		return (year%400 == 0);
	else
		return (year%4 == 0);
}


int month_length(int month, int year)
{
	switch (month) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 0:
    	return 31;
    	break;
    case 4:
    case 6:
    case 9:
    case 11:
    	return 30;
    	break;
    case 2:
    	if (is_run(year))
    		return 29;
    	else
    		return 28;
    	break;
    default:
    	return 31;
    }
}
