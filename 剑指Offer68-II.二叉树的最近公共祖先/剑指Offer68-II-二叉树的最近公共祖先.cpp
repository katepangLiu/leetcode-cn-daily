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
    TreeNode* ancestor;
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        ancestor = NULL;
        dfs(root, p, q);
        return ancestor;
    }

    int dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if( !root ) {
            return 0;
        }

        if( ancestor ) {
            return 0;
        }

        int count = 0;
        if( root == p || root == q ) {
            count++; 
        }

        count += dfs(root->left, p, q);
        count += dfs(root->right,p, q);
        if( count > 1 ) {
            ancestor = root;
        }

        return count > 0;
    }
};