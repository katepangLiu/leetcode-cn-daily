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
    bool isUnivalTree(TreeNode* root) {
        if( !root ) {
            return true;
        }
        return dfs(root, root->val);
    }

    bool dfs(TreeNode* root, int value) {
        if( !root ) {
            return true;
        }

        if( root->val != value ) {
            return false;
        }

        return dfs(root->left, value) && dfs(root->right, value);
    }

};