class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        stack<int> stk;
        vector<int> sum;
        int c = 1, s = 0;
        
        for (int i = digits.size() - 1; i >= 0; i--)
        {
            s = digits[i] + c;
            stk.push(s % 10);
            c = s / 10;
        }
        if (c)
            stk.push(c);
        
        while(!stk.empty())
        {
            sum.push_back(stk.top());
            stk.pop();
        }
        return sum;
    }
};