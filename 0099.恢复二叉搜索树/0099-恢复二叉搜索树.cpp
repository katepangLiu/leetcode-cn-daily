/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void recoverTree(TreeNode* root) {
        vector<int> nums;
        travel(root, nums);
        int x = -1;
        int y = -1;
        findSwap(nums, x, y);
        recover(root, x, y);
    }

    void travel(TreeNode* root, vector<int>& nums) {
        if(!root) {
            return;
        }

        travel(root->left, nums);
        nums.push_back(root->val);
        travel(root->right, nums);
    }

    void findSwap(const vector<int>& nums, int& x, int& y) {
        int n = nums.size();

        for( int i=0; i< n-1; i++ ) {
            if( nums[i+1] < nums[i] ) {
                y = nums[i+1] ;
                if( x == -1 ) {
                    x = nums[i];
                }
            }
        }
    }

    void recover(TreeNode* root, int x, int y) {
        if(!root) {
            return;
        }

        recover(root->left, x, y);
        if( root->val == x ) {
            root->val = y;
        } else if( root->val == y ) {
            root->val = x;
        }
        recover(root->right, x, y);
    }

};