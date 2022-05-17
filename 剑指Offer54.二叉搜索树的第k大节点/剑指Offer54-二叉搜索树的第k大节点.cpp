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
    int index;
    int ans;
public:
    int kthLargest(TreeNode* root, int k) {
        index = 0;
        ans = -1;
        dfs(root, k);
        return ans;
    }

    void dfs(TreeNode* root, int k) {
        if( !root ) {
            return ;
        }

        dfs(root->right, k);
        index++;
        if( k == index ) {
            ans = root->val;
        }
        dfs(root->left, k);
    }
};