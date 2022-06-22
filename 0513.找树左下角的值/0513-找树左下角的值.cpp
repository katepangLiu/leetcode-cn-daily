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
    vector<int> mm;
    int findBottomLeftValue(TreeNode* root) {
        dfs(root, 0);
        return mm[mm.size()-1];
    }

    void dfs(TreeNode* root, int level) {
        if(!root) {
            return;
        }

        if(mm.size() == level ) {
            mm.emplace_back( root->val );
        }

        dfs(root->left, level+1);
        dfs(root->right, level+1);
    } 
};