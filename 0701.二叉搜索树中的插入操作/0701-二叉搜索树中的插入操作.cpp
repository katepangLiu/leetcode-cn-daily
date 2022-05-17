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
    TreeNode* left;
    TreeNode* right;
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        left = nullptr;
        right = nullptr;

        dfs(root, val);
        //cout << left->val << endl;
        //cout << right->val << endl;

        TreeNode* node = new TreeNode(val);
        if( !left && !right ) {
            return node;
        } else if( left && left->right == nullptr ) {
            left->right = node;
        } else {
            right->left = node;
        }

        return root;
    }

    void dfs(TreeNode* root, int val) {    
        if( root == nullptr ) {
            return;
        }

        dfs( root->left, val);

        if( root->val < val ) {
            left = root;
        }

        if( right == nullptr ) {
            if( root->val > val ) {
                right = root;
            }
        }

        dfs( root->right, val);
    }
};