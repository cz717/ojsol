#include <stdio.h>
#include <stdlib.h>

int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridRowSize, int obstacleGridColSize) {
    int a[100][100];
    int i, j;

    for (i = 0; i < obstacleGridRowSize; i++) {
    	for (j = 0; j < obstacleGridColSize; j++) {
    		a[i][j] = 0;
    		if (!obstacleGrid[i][j]) {
    			if (i ==0 && j == 0)
    				a[i][j] = 1;
    			if (i > 0)
    				a[i][j] += a[i-1][j];
    			if (j > 0)
    				a[i][j] += a[i][j-1];
    		}
    	}
    }

    return a[obstacleGridRowSize-1][obstacleGridColSize-1];
}

int main(void) {
	return 0;
}