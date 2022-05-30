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
    int sumRootToLeaf(TreeNode* root) {
        int sum = 0;
        int cur = 0;
        dfs(root, sum, cur);
        return sum;
    }

    void dfs(TreeNode* root, int& sum, int cur) {
        if( !root ) {
            return;
        }

        cur = cur*2 + root->val;
        cout << cur << endl;

        if( !root->left && !root->right ) {
            sum += cur;
            return;
        }

        dfs(root->left, sum, cur);
        dfs(root->right, sum, cur);
    }
};