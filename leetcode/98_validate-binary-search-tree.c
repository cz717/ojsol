/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isValidBST(struct TreeNode* root) {
    if (root == NULL)
        return true;
    
    struct TreeNode* l = root->left;
    struct TreeNode* r = root->right;
    struct TreeNode *pre = l, *suc = r;
    while (pre != NULL && pre->right != NULL)
        pre = pre->right;
    while (suc != NULL && suc->left != NULL)
        suc = suc->left;
        
    if (l != NULL && l->val >= root->val)
        return false;
    if (r != NULL && r->val <= root->val)
        return false;
    if (pre != NULL && pre->val >= root->val)
        return false;
    if (suc != NULL && suc->val <= root->val)
        return false;
    
    return isValidBST(l) && isValidBST(r);
}