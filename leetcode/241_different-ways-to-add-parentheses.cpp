class Solution {
public:  
    int cal(int a, int op, int b)
    {
        switch(op)
        {
        case (int)'+':
            return a + b;
        case (int)'-':
            return a - b;
        case (int)'*':
            return a * b;
        default:
            return 0;
        }
    }
    
    vector<int> rs(vector<int> &exp, int b, int e)
    {
        vector<int> result;
        if (b == e)
            result.push_back(exp[b]);
        else
        {
            for (int i = b + 1; i < e; i += 2)
            {
                vector<int> rsl = rs(exp, b, i-1);
                vector<int> rsr = rs(exp, i+1, e);
                for (int j : rsl)
                    for (int k : rsr)
                        result.push_back(cal(j, exp[i], k));
            }
        }
        
        return result;
    }
    
    vector<int> diffWaysToCompute(string input) {
        // input
        vector<int> exp;
        istringstream iss(input);
        int num;
        char op;
        bool flag = true;
        while(iss)
        {
            if (flag)
            {
                iss >> num;
                exp.push_back(num);
            }
            else
            {
                iss >> op;
                exp.push_back((int) op);
            }
            flag = !flag;
        }
        
        // search
        return rs(exp, 0, exp.size() - 2);
    }
};