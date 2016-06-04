class Solution {
public:
    bool canFinish(int num, vector<pair<int, int>>& pre) {
        if (num <= 1)
            return true;
            
        vector<int> * adjl = new vector<int>[num];
        int * indg = new int[num]();
        
        for (auto &x : pre)
        {
            adjl[x.first].push_back(x.second);
            ++indg[x.second];
        }
        
        queue<int> q;
        for (int i = 0; i < num; i++)
            if (indg[i] == 0)
                q.push(i);
                
        set<int> tsd;
        while (!q.empty())
        {
            int x = q.front();
            q.pop();
            
            tsd.insert(x);
            for (auto & i : adjl[x])
            {
                --indg[i];
                if (indg[i] == 0)
                    q.push(i);
            }
        }
        
        if (tsd.size() < num)
            return false;
        else
            return true;
    }
};