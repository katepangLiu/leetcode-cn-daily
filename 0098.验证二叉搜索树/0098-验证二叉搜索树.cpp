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
    bool isValidBST(TreeNode* root) {
        return isVaildBSTCore(root, LLONG_MIN, LLONG_MAX);
    }

    bool isVaildBSTCore(TreeNode* root, long long min, long long max){
        if( !root ){
            return true;
        }

        long long cur = root->val;
        if( cur <= min || cur >= max ){
            return false;
        }

        return isVaildBSTCore(root->left,  min, cur)&&isVaildBSTCore(root->right, cur, max);
    }
};