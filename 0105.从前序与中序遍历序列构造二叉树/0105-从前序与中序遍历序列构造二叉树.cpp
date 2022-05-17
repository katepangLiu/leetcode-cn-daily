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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return dfs(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }

    TreeNode* dfs(vector<int>& preorder, int pl, int pr, vector<int>& inorder, int il, int ir) {
        if( pl > pr || il > ir ) {
            return NULL;
        }

        TreeNode* root = new TreeNode(preorder[pl]);
        int i = 0;
        while( inorder[il+i] != preorder[pl] ) {
            i++;
        }

        root->left = dfs(preorder, pl+1, pr+i, inorder, il, il+i-1);
        root->right = dfs(preorder, pl+i+1, pr, inorder, il+i+1, ir);
        return root;
    }
};