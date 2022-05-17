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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        if( !root ) {
            return ans;
        }

        queue< pair<TreeNode*, int> > q;
        q.push( {root, 0} );
        double levelSum = 0;
        int levelCnt = 0;

        while( !q.empty() ) {
            TreeNode* node = q.front().first;
            int level = q.front().second;
            q.pop();
            levelSum += node->val;
            levelCnt++;

            if( q.empty() || q.front().second > level ) {
                ans.push_back(levelSum/levelCnt );
                levelSum = 0.0;
                levelCnt = 0;
            }

            if( node->left ) {
                q.push({node->left, level+1});
            } 
            if( node->right ) {
                q.push({node->right, level+1});
            }
        } 

        return ans;
    }
};