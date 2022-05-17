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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leafs1;
        vector<int> leafs2;

        dfs(root1, leafs1);
        dfs(root2, leafs2);
        if( leafs1.size() != leafs2.size() ) {
            return false;
        }

        for( int i=0; i<leafs1.size(); i++ ) {
            if( leafs1[i] != leafs2[i] ) {
                return false;
            }
        }

        return true;
    }

    void dfs(TreeNode* root, vector<int>& leafs) {
        if( !root ) {
            return ;
        }

        dfs(root->left, leafs);
        if( !root->left && !root->right ) {
            leafs.push_back(root->val);
        }
        dfs(root->right, leafs);
    }

};