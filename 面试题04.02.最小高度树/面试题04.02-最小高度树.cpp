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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBSTCore( nums, 0 ,nums.size()-1 );
    }

    TreeNode* sortedArrayToBSTCore(vector<int>& nums, int l, int r) {
        if( l > r ){
            return NULL;
        }

        int mid = (l+r)/2;
        TreeNode* node = new TreeNode(nums[mid]);
        TreeNode* left = sortedArrayToBSTCore( nums, l, mid -1 );
        TreeNode* right = sortedArrayToBSTCore( nums, mid+1, r);
        node->left = left;
        node->right = right;
        return node;
    }

};