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
    bool isVaild;
public:
    bool isBalanced(TreeNode* root) {
        isVaild = true;
        dfs(root);
        return isVaild;    
    }

    int dfs(TreeNode* root) {
        if( !root ) {
            return true;
        }

        int leftHight = dfs(root->left);
        int rightHeight = dfs(root->right);
        if( abs(leftHight-rightHeight) > 1 ) {
            isVaild =false;
        }

        return max(leftHight, rightHeight) + 1;
    }
};