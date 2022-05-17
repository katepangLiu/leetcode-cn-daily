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
    int minDiff;
    int prev;
public:
    int getMinimumDifference(TreeNode* root) {
        minDiff = INT_MAX;
        if( !root ) {
            return 0;
        }
        prev = root->val;
        dfs(root);
        return minDiff;
    }

    void dfs(TreeNode* root) {
        if( !root ) {
            return;
        }

        dfs(root->left);
        int diff = abs(root->val - prev);
        prev = root->val;
        if( diff != 0 ) {
            minDiff = min(diff, minDiff);
        }
        dfs(root->right);
    }
};