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
    int tilt;
public:
    int findTilt(TreeNode* root) {
        tilt = 0;
        dfs(root);
        return tilt;
    }

    int dfs(TreeNode* root) {
        if( !root ) {
            return false;
        }

        int left = dfs(root->left);
        int right = dfs(root->right);
        tilt += abs(left - right);
        return root->val + left + right;
    }
};