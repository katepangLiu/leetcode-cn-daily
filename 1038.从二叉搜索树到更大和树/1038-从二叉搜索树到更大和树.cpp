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
    int greater;
public:
    TreeNode* bstToGst(TreeNode* root) {
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
        greater += root->val;
        root->val = greater;
        dfs(root->left);
    }
};