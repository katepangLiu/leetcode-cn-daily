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
    int val;
public:
    TreeNode* convertBST(TreeNode* root) {
        if( !root ) {
            return NULL;
        }

        dfs(root);
        return root;
    }

    void dfs(TreeNode* root) {
        if( !root ) {
            return;
        }

        dfs(root->right);
        val += root->val;
        root->val = val;
        dfs(root->left);
    }
};