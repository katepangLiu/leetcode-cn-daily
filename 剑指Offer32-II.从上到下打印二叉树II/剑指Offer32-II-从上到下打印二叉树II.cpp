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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        if( !root ) {
            return ans;
        }

        queue< pair<TreeNode*,int> > q;
        q.push( {root, 0} );
        int lastLevel = -1;

        while( !q.empty() ) {
            TreeNode* node = q.front().first;
            int level = q.front().second;
            q.pop();
            if( level > lastLevel ) {
                lastLevel = level;
                ans.push_back({});
            }
            ans[level].push_back(node->val);
            if( node->left ) {
                q.push({node->left,level+1});
            }
            if( node->right ) {
                q.push({node->right,level+1});
            }
        }

        return ans;
    }
};