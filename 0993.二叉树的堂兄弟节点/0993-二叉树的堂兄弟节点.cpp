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
    int searchRet[2][2];
    int x;
    int y;
public:
    bool isCousins(TreeNode* root, int x, int y) {
        this->x = x;
        this->y = y;
        dfs(root, 0, 0);
        return searchRet[0][0] != searchRet[1][0] && searchRet[0][1] == searchRet[1][1];
    }

    void dfs(TreeNode* root, int parentVal, int depth) {
        if( !root ) {
            return;
        }

        if( x == root->val ) {
            searchRet[0][0] = parentVal;
            searchRet[0][1] = depth;
        } else if ( y == root->val ){
            searchRet[1][0] = parentVal;
            searchRet[1][1] = depth;
        }

        dfs(root->left, root->val, depth+1);
        dfs(root->right, root->val, depth+1);
    }
};