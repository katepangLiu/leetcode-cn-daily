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
    TreeNode* searchBST(TreeNode* root, int val) {
        if( !root ) {
            return root;
        }

        if( val == root->val ) {
            return root;
        }

        TreeNode* ret = searchBST(root->left, val);
        if( ret ) {
            return ret;
        } else {
            return searchBST(root->right, val);
        }
    }
};