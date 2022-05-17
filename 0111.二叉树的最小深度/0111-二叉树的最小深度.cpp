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
    int minDepth(TreeNode* root) {
        if( !root ) {
            return 0;
        }

        if( !root->left && !root->right ) {
            return 1;
        }

        int leftMinDepth = minDepth(root->left) ;
        int rightMinDepth = minDepth(root->right) ;
        if( !leftMinDepth ) {
            return rightMinDepth + 1;
        }
        if( !rightMinDepth ) {
            return leftMinDepth + 1;
        }

        return min( leftMinDepth, rightMinDepth) +1 ;
    }
};