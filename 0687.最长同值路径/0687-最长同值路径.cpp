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
    int ans;
public:
    int longestUnivaluePath(TreeNode* root) {
        ans = 0;
        dfs(root);
        return ans;
    }

    int dfs(TreeNode* root) {
        if( !root ) {
            return 0;
        }

        int singlePath = 0;
        int doublePath = 0;
        int left = dfs(root->left);
        int right = dfs(root->right);
        
        if( root->left && root->val == root->left->val && root->right && root->val == root->right->val ) {
            doublePath = left + right +2;
        }

        if( root->left && root->val == root->left->val ) {
            singlePath = left+1;
        }
        if( root->right && root->val == root->right->val ) {
            singlePath = max(singlePath, right+1);
        }

        ans = max( ans, max(singlePath, doublePath));
        return singlePath;//对于上一层的贡献，只能计算单边的路径;
    }    
};