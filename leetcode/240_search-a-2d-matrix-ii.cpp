class Solution {
public:

    bool search(vector<vector<int>>& matrix, int target,
                int xa, int xb, int ya, int yb) 
    {
        if (xa == xb || ya == yb)
            return false;
        
        int xm = (xa + xb) / 2;
        int ym = (ya + yb) / 2;
        
        if (matrix[xm][ym] == target)
            return true;
        else if (matrix[xm][ym] < target)
        {
            bool s1 = search(matrix, target, xa, xm + 1, ym + 1, yb);
            bool s2 = search(matrix, target, xm + 1, xb, ya, ym + 1);
            bool s3 = search(matrix, target, xm + 1, xb, ym + 1, yb);
            return (s1 || s2 || s3);
        }
        else
        {
            bool s1 = search(matrix, target, xm, xb, ya, ym);
            bool s2 = search(matrix, target, xa, xm, ya, ym);
            bool s3 = search(matrix, target, xa, xm, ym, yb);
            return (s1 || s2 || s3);
        }
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int xa = 0, xb = matrix.size();
        int ya = 0, yb = matrix[0].size();
        
        return search(matrix, target, xa, xb, ya, yb);
    }
};