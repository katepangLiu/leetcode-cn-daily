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
    vector<string> ans;
public:    
    vector<string> binaryTreePaths(TreeNode* root) {
        dfs(root, "", true);
        return ans;
    }

    void dfs(TreeNode* root, string buf, bool isRoot) {
        if( !root ) {
            return;
        }

        if( !isRoot ) {
            buf += "->";
        }

        buf += to_string(root->val);
        if( !root->left && !root->right ) {
            ans.push_back(buf);
            return;
        }

        dfs(root->left, buf, false);
        dfs(root->right, buf, false);
    }
};