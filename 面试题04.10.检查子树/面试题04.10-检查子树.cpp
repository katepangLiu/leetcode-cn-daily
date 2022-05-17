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
    bool checkSubTree(TreeNode* t1, TreeNode* t2) {
        if( !t2 ) {
            return true;
        }
        if( !t1 ) {
            return false;
        }

        return dfs(t1, t2) || checkSubTree(t1->left, t2) || checkSubTree(t1->right, t2);
    }

    // �ж�t2 �� t1 ������������t1��t2��root���;
    bool dfs(TreeNode* t1, TreeNode* t2) {
        if( !t2 ) {
            return true;
        }
        if( !t1 ) {
            return false;
        }

        if( t1->val != t2->val ) {
            return false;
        }
        return dfs(t1->left, t2->left) && dfs(t1->right, t2->right);
    }
};