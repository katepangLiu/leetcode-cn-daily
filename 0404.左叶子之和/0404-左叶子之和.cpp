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
    int sum;
public:
    int sumOfLeftLeaves(TreeNode* root) {
        sum = 0;
        dfs(root, false);
        return sum;
    }

    void dfs(TreeNode* root, bool left) {
        if( !root ) {
            return;
        }

        if( !root->left && !root->right && left ) {
            sum += root->val;
        } 

        dfs( root->left, true );
        dfs( root->right, false);
    }
};