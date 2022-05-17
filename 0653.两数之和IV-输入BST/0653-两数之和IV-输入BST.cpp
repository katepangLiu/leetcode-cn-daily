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
    bool findTarget(TreeNode* root, int k) {
        vector<int> vec;
        dfs(root, vec);
        int l = 0;
        int r = vec.size()-1;
        while( l<r ) {
            int sum = vec[l] + vec[r];
            if( sum == k ) {
                return true;
            }
            if( sum < k ) {
                l++;
            } else {
                r--;
            }
        }
        return false;
    }

    void dfs(TreeNode* root, vector<int>& vec) {
        if( !root ) {
            return;
        }

        dfs(root->left, vec);
        vec.push_back(root->val);
        dfs(root->right, vec);
    } 

};