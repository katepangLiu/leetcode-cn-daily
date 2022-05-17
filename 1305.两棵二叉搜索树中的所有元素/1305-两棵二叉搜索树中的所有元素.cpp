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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> vec1, vec2;

        getAllElements(root1, vec1);
        getAllElements(root2, vec2);

        int n1 = vec1.size();
        int n2 = vec2.size();
        vector<int> ans(n1 + n2);

        int i=0, j=0, k=0;

        while( i<n1 || j<n2 ) {
            int a = INT_MAX;
            int b = INT_MAX;
            if( i < n1 ) {
                a = vec1[i];
            }
            if( j < n2 ) {
                b = vec2[j];
            }

            if(  a > b ) {
                ans[k] = b;
                j++;
                k++;
            } else {
                ans[k] = a;
                i++;
                k++;
            }
        }

        return ans;

    }

    void getAllElements(TreeNode* root, vector<int>& vec) {
        if( !root ) {
            return;
        }

        getAllElements(root->left, vec);
        vec.push_back(root->val);
        getAllElements(root->right, vec);
    }
};