class Solution {
public:
    struct hnode
    {
        int pa;
        int pb;
        int sum;
        hnode (int a, int b, int s)
            : pa(a), pb(b), sum(s)
        {}
        
        hnode& operator = (hnode& n)
        {
            pa = n.pa;
            pb = n.pb;
            sum = n.sum;
            return *this;
        }
    };
    
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> r;
        if (nums1.size() == 0 || nums2.size() == 0)
            return r;
            
        // build the heap
        int s = nums1.size();
        vector<hnode> h;
        h.push_back(hnode(-1, -1, 0));
        for (int i = 0; i < s; i++)
            h.push_back(hnode(i, 0, nums1[i]+nums2[0]));
        
        
        if (k > nums1.size() * nums2.size())
            k = nums1.size() * nums2.size();
        for (int i = 0; i < k; i++)
        {
            r.push_back(pair<int,int>(nums1[h[1].pa], nums2[h[1].pb]));
            
            // cal
            if (h[1].pb == nums2.size() - 1)
            {
                h[1] = h[s];
                --s;
            }
            else {
                ++(h[1].pb);
                h[1].sum = nums1[h[1].pa] + nums2[h[1].pb];
            }
            
            // down
            hnode temp = h[1];
            int p = 1;
            int lc, rc, next;
            while(1)
            {
                lc = p * 2;
                rc = p * 2 + 1;
                if (lc > s)
                    break;
                if (rc > s)
                    next = lc;
                else
                    next = (h[lc].sum < h[rc].sum) ? lc : rc;
                    
                if (h[next].sum < temp.sum)
                {
                    h[p] = h[next];
                    p = next;
                }
                else
                    break;
            }
            h[p] = temp;
        }
        
        return r;
    }
};