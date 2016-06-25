class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max, last;
        max = last = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if (last > 0)
                last += nums[i];
            else
                last = nums[i];
                
            if (max < last)
                max = last;
        }
        return max;
    }
};