/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector< vector<int> > res;

        foobar(root, 0, res);
        return res;
    }
    
    void foobar(TreeNode *t, int level, vector<vector<int>> &res) {
        if (t == NULL)
            return;
        
        vector<int> emptyv;
        while(res.size() <= level)
            res.push_back(emptyv);
        
        res[level].push_back(t->val);
        foobar(t->left, level+1, res);
        foobar(t->right, level+1, res);
    }
};