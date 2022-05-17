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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if( !t ) {
            return true;
        }
        if( !s ) {
            return false;
        }

        return isSubtreeFromRoot(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t);
    }

    bool isSubtreeFromRoot(TreeNode* s, TreeNode* t) {
        if( !t && !s ) {
            return true;
        }

        if( !t || !s ) {
            return false;
        }

        return s->val == t->val && isSubtreeFromRoot(s->left, t->left) && isSubtreeFromRoot(s->right, t->right);
    }

};