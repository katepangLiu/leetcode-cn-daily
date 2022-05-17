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
    int sumNumbers(TreeNode* root) {
        ans = 0;
        dfs(root, 0);
        return ans;
    }

    void dfs( TreeNode* root, int path) {
        if( !root ) {
            return;
        }
        
        path = path*10 + root->val;
        //cout << path << endl;
        if( !root->left && !root->right ) {
            ans += path;
        }

        dfs(root->left, path);
        dfs(root->right, path);
    }
};