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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        dfs(root, 0, ans);
        return ans;
    }

    void dfs(TreeNode* root, int level, vector<int>& ans) {
        if( !root ) {
            return;
        }

        if( ans.size() == level ) {
            ans.emplace_back(root->val);
        } else {
            ans[level] = max(ans[level], root->val);
        }
        if( root->left )
            dfs(root->left, level+1, ans);
        if( root->right )
            dfs(root->right, level+1, ans);
    }
};