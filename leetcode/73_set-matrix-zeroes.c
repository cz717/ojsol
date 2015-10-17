#include <stdio.h>
#include <stdlib.h>

void setZeroes(int** matrix, int matrixRowSize, int matrixColSize) {
    int r, c;
    int i, j;
    int rz = 0, cz = 0;
    for (r = 0; r < matrixRowSize; r++) {
    	for (c = 0; c < matrixColSize; c++) {
    		if (r == 0 || c == 0) {
    			if (matrix[r][c] == 0) {
    				if (r == 0)	rz = 1;
    				if (c == 0)	cz = 1;
    			}
    		}
    		else if (matrix[r][c] == 0) {
    			for (i = 0; i < r; i++)
    				matrix[i][c] = 0;
    			for (j = 0; j < c; j++)
    				matrix[r][j] = 0;
    		}
    		else if (matrix[r][0] == 0 || matrix[0][c] == 0)
    			matrix[r][c] = 0;
    	}
    }
    if (rz)
    	for (i = 0; i < matrixRowSize; i++)
    		matrix[0][i] = 0;
    if (cz)
    	for (j = 0; j < matrixColSize; j++)
    		matrix[j][0] = 0;
}