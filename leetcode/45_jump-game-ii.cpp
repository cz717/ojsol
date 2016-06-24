class Solution {
public:
    int jump(vector<int>& nums) {
        auto s = nums.size();
        int steps = 0;
        list<int> from;
        list<int> mins;
        
        from.push_front(s-1);
        mins.push_front(0);
        
        for (int i = s-2; i >= 0; --i)
        {
            steps = s;
            int far = min(s-1, i + nums[i]);
            for (list<int>::iterator f = from.begin(), m = mins.begin();
                 f != from.end() && m != mins.end();
                 ++f, ++m)
            {
                if (far >= *f)
                {
                    if (steps > *m + 1)
                        steps = *m + 1;
                }
                else
                    break;
            }
            
            
            if (mins.front() >= steps)
            {
                from.front() = i;
                mins.front() = steps;
            }
            else {
                from.push_front(i);
                mins.push_front(steps);
            }
            
        }
        
        return steps;
    }
    
    int min(int x, int y)
    {
        return (x > y) ? y : x;
    }
};