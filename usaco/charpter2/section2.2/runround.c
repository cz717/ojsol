/*
ID: huajian2
LANG: C
TASK: runround
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int num[10];
bool touched[10];
bool have[10];

int length(int num)
{
	int len = 0;
	while (num > 0) {
		len++;
		num /= 10;
	}
	return len;
}

bool is_runround(int n)
{
	int i, temp;
	int len = length(n);

	for (i = 0; i < 10; i++) {
		have[i] = false;
		touched[i] = false;
	}

	for (i = len-1; i >= 0; i--) {
		temp = n % 10;
		if (have[temp] || temp == 0)
			return false;
		else
			have[temp] = true;

		num[i] = temp;
		n /= 10;
	}

	int this = 0;
	while(1) {
		if (!touched[this])
			touched[this] = true;
		else {						/* touched twice */
			if (this != 0)				/* not first */
				return false;
			
			for (i = 0; i < len; i++)	/* not all touched */
				if (!touched[i])
					return false;

			return true;
		}

		this = (this + num[this]) % len;
	}
}


main () {
    FILE *fin  = fopen ("runround.in", "r");
    FILE *fout = fopen ("runround.out", "w");
    int n;
    fscanf (fin, "%d", &n);

    for (++n; ; ++n) {
    	if (is_runround(n)) {
    		fprintf(fout, "%d\n", n);
    		exit(0);
    	}
    }
}
