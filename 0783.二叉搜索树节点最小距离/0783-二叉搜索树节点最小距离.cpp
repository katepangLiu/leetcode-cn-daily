/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int minDiff = INT_MAX;
    int prev = -1;

    int minDiffInBST(TreeNode* root) {
        dfs(root);
        return minDiff;
    }

    void dfs(TreeNode* root) {
        if( !root ) {
            return;
        }

        dfs(root->left);

        if( prev >= 0 ) {
            int diff = root->val - prev;
            minDiff = min( diff, minDiff);
        } 
        prev = root->val;

        dfs(root->right);
    }
};