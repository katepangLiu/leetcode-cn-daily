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
    TreeNode* mirrorTree(TreeNode* root) {
        if( !root ) {
            return NULL;
        }

        swap( root->left, root->right );
        root->left = mirrorTree(root->left);
        root->right = mirrorTree(root->right);
        return root;
    }
};