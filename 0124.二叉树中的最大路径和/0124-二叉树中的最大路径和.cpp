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
    int maxSum;
public:
    int maxPathSum(TreeNode* root) {
        maxSum = INT_MIN;
        dfs(root);
        return maxSum;
    }

    int dfs(TreeNode* root) {
        if( !root ) {
            return 0;
        }

        int left = dfs(root->left);
        int right = dfs(root->right);
        maxSum = max( maxSum, root->val+left+right);
        return  max(0, root->val + max(left, right));
    }

};