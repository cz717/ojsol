class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector< vector<int> > res;
        vector<int> temp;
        int cnt = 0, s, i;
        int size = nums.size();
        
        sort(nums.begin(), nums.end());
        for (s = 0; s < 1<<size; s++) {
            temp.clear();
            for (i = 0; i < size; i++)
                if (s & 1<<i)
                    temp.push_back(nums[i]);
            res.push_back(temp);
        }
        return res;
    }
    
};