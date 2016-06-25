class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        
        if (size == 0)
            return 0;
        if (size == 1)
            return nums[0];
        
        int a = nums[0], b = max(nums[0], nums[1]), temp;
        for (int i = 2; i < size; i++)
        {
            temp = max(b, a + nums[i]);
            a = b;
            b = temp;
        }
        return b;
    }
    
    int max(int a, int b)
    {
        return (a > b) ? a : b;
    }
};