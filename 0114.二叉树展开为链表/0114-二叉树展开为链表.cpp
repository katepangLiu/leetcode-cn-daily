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
    TreeNode* prev;
public:
    void flatten(TreeNode* root) {
        TreeNode tmpRoot(0);
        prev = &tmpRoot;
        dfs(root);
        root = tmpRoot.right;
    }

    void dfs(TreeNode* root) {
        if( !root ) {
            return;
        }

        prev->right = root;
        prev = prev->right;
        TreeNode* oldRight = root->right;
        dfs(root->left);        
        dfs(oldRight);
        root->left = NULL;
        return;
    }
};