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
private: 
    int maxd;

public:
    int diameterOfBinaryTree(TreeNode* root) {
        maxd = 0;
        depth(root);
        return maxd;
    }

    int depth( TreeNode* root ){
        if( !root ){
            return 0;
        }

        int left = depth(root->left);
        int right = depth(root->right);
        maxd = max( left+right, maxd );
        return max(left, right)+1;
    }

};