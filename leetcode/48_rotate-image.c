void rotate(int** matrix, int matrixRowSize, int matrixColSize) {
    int x[4], y[4];
    int temp, i;
    int n = matrixRowSize;
    
    for (x[0] = 0; x[0] < (matrixRowSize + 1) / 2; x[0]++) {
        for (y[0] = 0; y[0] < (matrixColSize + ((matrixColSize%2)?-1:1)) / 2; y[0]++) {
            for (i = 1; i < 4; i++) {
                x[i] = y[i-1];
                y[i] = matrixColSize - x[i-1] - 1;
            }
            
            temp = matrix[x[3]][y[3]];
            for (i = 3; i >= 1; i--)
                matrix[x[i]][y[i]] = matrix[x[i-1]][y[i-1]];
            matrix[x[0]][y[0]] = temp;
        }
    }
}