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
    int sumRootToLeaf(TreeNode* root) {
        int base = 10^9 + 7;
        int sum = 0;
        dfs(root, base, sum, 0);
        return sum;
    }

    void dfs(TreeNode* root, int base, int& sum, long long tmp) {
        if( !root ) {
            return;
        }

        tmp = 2*tmp + root->val;
        if( !root->left && !root->right ) {
            sum += tmp;
        }

        dfs(root->left, base, sum, tmp);
        dfs(root->right, base, sum, tmp);
    }

};