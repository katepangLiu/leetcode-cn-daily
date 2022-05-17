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
    int maxCnt;
    int curVal;
    int curCnt;
    vector<int> ans;
public:
    vector<int> findMode(TreeNode* root) {
        if( !root ) {
            return {};
        }

        maxCnt = 1;
        curCnt = 0;
        curVal = root->val;
        dfs(root);
        return ans;
    }

    void dfs(TreeNode* root) {
        if( !root ) {
            return;
        }

        dfs(root->left);
        if( root->val != curVal ) {
            curCnt = 0;
        }
        curCnt++;

        if( curCnt > maxCnt ) {
            ans.clear();
            ans.emplace_back( root->val );
            maxCnt = curCnt;
        } else if( curCnt == maxCnt ) {
            ans.emplace_back( root->val );
        }
        curVal = root->val;

        dfs(root->right);
    }
};