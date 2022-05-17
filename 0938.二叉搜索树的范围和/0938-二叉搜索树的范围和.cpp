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
    bool inRange;
    bool end;
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        inRange = false;
        end = false;
        int sum = 0;
        dfs(root, L, R, sum);
        return sum;
    }

    void dfs(TreeNode* root, int L, int R, int& sum) {
        if(end) {
            return ;
        }
        if( !root ) {
            return;
        }

        dfs(root->left, L, R, sum);

        if( root->val == L ) {
            inRange = true;                        
        }
        if( inRange ) {
            sum += root->val;
        }
        if( root->val == R ) {
            inRange =false;
            end = true;
        }
        
        dfs(root->right, L, R, sum);
    }

};