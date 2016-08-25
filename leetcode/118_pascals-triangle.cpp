class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        int r, c;
        vector<vector<int>> t;
        for (r = 0; r < numRows; r++ )
        {
            t.push_back(vector<int>(r+1, 1));
            for (c = 1; c < r; c++)
                t[r][c] = t[r-1][c-1] + t[r-1][c];
        }
        return t;
    }
};