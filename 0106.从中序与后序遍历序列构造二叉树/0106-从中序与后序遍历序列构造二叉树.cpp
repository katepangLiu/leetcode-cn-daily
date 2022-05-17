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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return dfs(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1 );
    }

    TreeNode* dfs(vector<int>& inorder, int iBeg, int iEnd, vector<int>& postorder, int pBeg, int pEnd) {
        cout << iBeg << ',' << iEnd << ',' << pBeg << ',' << pEnd << endl ;

        if( iBeg > iEnd || pBeg > pEnd ) {
            return NULL;
        }

        TreeNode* root = new TreeNode( postorder[pEnd] );
        int step = 0;
        while( inorder[iBeg+step] != postorder[pEnd] ) {
            step++;
        }

        if( iBeg == iEnd ) {
            return root;
        }

        root->left = dfs(inorder, iBeg, iBeg+step-1, postorder, pBeg, pBeg+step-1 );
        root->right = dfs( inorder, iBeg+step+1, iEnd, postorder, pBeg+step, pEnd-1 );

        return root;
    }
};