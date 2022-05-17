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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> s;
        if( !root ) {
            return ans;
        }

        s.push(root);
        while(!s.empty()) {
            TreeNode* node = s.top();
            s.pop();
            if( nullptr != node ) {
                s.push(node);
                s.push(nullptr);
                if(node->right) {
                    s.push(node->right);
                }
                if(node->left) {
                    s.push(node->left);            
                }
            }else {
                ans.push_back(s.top()->val);
                s.pop();
            }
        }

        return ans;
    }
};