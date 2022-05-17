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
    bool hasPathSum(TreeNode* root, int sum) {
        return dfs(root, sum, 0);
    }

    bool dfs(TreeNode* root, int sum, int curSum) {
        if( root == nullptr ) {
            return false;
        }

        curSum += root->val;
        if( !root->left &&!root->right && curSum == sum ) {
            return true;
        }

        return dfs(root->left,sum, curSum )||dfs(root->right, sum, curSum);
    }

};