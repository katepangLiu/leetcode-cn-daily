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
    vector<int> rightSideView(TreeNode* root) {
        if( !root ) {
            return {};
        }

        vector<int> ans ;
        queue< pair<TreeNode*, int> > help;
        queue< pair<TreeNode*, int> > q;
        help.push( {root, 0} );
        q.push( {root, 0} );

        int tmp = 0;
        int lastLevel = 0;

        while( !q.empty() ) {
            TreeNode* node = q.front().first;
            int level = q.front().second;
            q.pop();

            if( level != lastLevel ) {
                ans.push_back(tmp);
                lastLevel = level;
            }

            tmp = node->val;
            if( node->left ) {
                q.push( { node->left, level+1 } );
            }
            if( node->right ) {
                q.push( {node->right, level+1} );
            }
        }

        ans.push_back( tmp );

        return ans;
    }
};