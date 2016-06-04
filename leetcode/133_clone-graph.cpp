/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node) return nullptr;
        
        map<UndirectedGraphNode*, UndirectedGraphNode*> nds, ods;
        
        UndirectedGraphNode* newroot = new UndirectedGraphNode(node->label);
        nds[node] = newroot;
        
        while(!nds.empty())
        {
            UndirectedGraphNode *oldnd = nds.begin()->first;
            UndirectedGraphNode *newnd = nds.begin()->second;
            nds.erase(nds.begin());
            ods[oldnd] = newnd;
            
            for (auto &x : oldnd->neighbors)
            {
                if (ods.find(x) != ods.end())
                    newnd->neighbors.push_back(ods[x]);
                else if (nds.find(x) != nds.end())
                    newnd->neighbors.push_back(nds[x]);
                else {
                    nds[x] = new UndirectedGraphNode(x->label);
                    newnd->neighbors.push_back(nds[x]);
                }
            }
        }
        
        return newroot;
    }
};