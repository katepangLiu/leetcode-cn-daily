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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if( !root ) {
            return {};
        }
        vector<vector<int>> res;
        queue<pair<TreeNode*, int>> q; 
        q.push( {root,0} );
        int lastLevel = -1;
        int level = 0;
        while( !q.empty() ) {
            TreeNode* node = q.front().first;
            level =  q.front().second;
            q.pop();
            if( level > lastLevel ) {
                lastLevel++;
                vector<int> vec = {};
                res.push_back( vec );
            }
            res[level].push_back( node->val );
            
            if( node->left ) {
                q.push( {node->left, level+1} );
            }
            if( node->right ) {
                q.push( {node->right, level+1} );
            }
        }

        reverse( res.begin(), res.end() ) ;
        return res;
    }
};