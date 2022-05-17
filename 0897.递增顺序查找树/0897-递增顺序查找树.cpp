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
    TreeNode* pNode;    
public:
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode tmphead(0);
        pNode = &tmphead;
        dfs(root);
        return tmphead.right;
    }

    void dfs( TreeNode* root) {
        if( !root ) {
            return;
        }

        dfs(root->left);
        
        pNode->right = root;
        root->left = NULL;
        pNode = pNode->right;
        
        dfs(root->right);
    }
};