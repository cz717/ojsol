class Solution {
public:
    bool canJump(vector<int>& nums) {
        int last = nums.size() - 1;
        bool can = true;
        for (int i = nums.size() - 2; i >= 0; --i)
        {
            if ((i + nums[i]) >= last)
            {
                can = true;
                last = i;
            }
            else
                can = false;
        }
        
        return can;
    }

};