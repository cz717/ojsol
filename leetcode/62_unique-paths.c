#include <stdio.h>
#include <stdlib.h>


int uniquePaths(int m, int n) {
    // int **a = (int **) malloc(sizeof(int) * m * n);
    int a[100][100];
    int i, j;

    for (i = 0; i < m; i++) {
    	for (j = 0; j < n; j++) {
    		a[i][j] = 0;
    		if (i == 0 && j == 0)
    			a[i][j] = 1;
    		if (i > 0)
    			a[i][j] += a[i-1][j];
    		if (j > 0)
    			a[i][j] += a[i][j-1];
    	}
    }

    // free(a);
    return a[m-1][n-1];
}

int main(void) {

	printf("%d\n", uniquePaths(2,3));

	return 0;
}