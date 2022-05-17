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
    bool balanced;
public:
    bool isBalanced(TreeNode* root) {
        balanced = true;
        dfs(root);
        return balanced;
    }

    int dfs(TreeNode* root) {
        if( !root ) {
            return 0;
        }

        int leftDepth = dfs(root->left);
        int rightDepth = dfs(root->right);
        balanced = balanced && (abs(leftDepth-rightDepth) <=1 );
        return max(leftDepth, rightDepth) + 1;
    }
};