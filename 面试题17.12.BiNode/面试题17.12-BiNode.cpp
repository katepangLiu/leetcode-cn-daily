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
    TreeNode* convertBiNode(TreeNode* root) {
        TreeNode tmpRoot(0);
        pNode = &tmpRoot;
        dfs(root);
        return tmpRoot.right;
    }

    void dfs(TreeNode* root) {
        if( !root ) {
            return;
        }

        dfs(root->left);
        pNode->right = root;
        pNode = pNode->right;
        root->left = NULL;
        dfs(root->right);
    }
};