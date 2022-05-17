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
    int rob(TreeNode* root) {
        auto [ rootInclude, rootExclude ] = dfs(root);
        return max( rootInclude,  rootExclude);
    }

    pair<int, int> dfs(TreeNode* root) {
        if( !root) {
            return {0, 0};
        }

        auto [l, lExclude] = dfs(root->left);
        auto [r, rExclude] = dfs(root->right);

        return {root->val+lExclude+rExclude, max(l, lExclude) + max(r, rExclude) };
    }
};