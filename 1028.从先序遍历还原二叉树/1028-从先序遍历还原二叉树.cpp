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
    TreeNode* recoverFromPreorder(string S) {
        int index = 0;
        return recover(S, index, 0);
    }

    TreeNode* recover(string S, int& index, int expectDepth) {
        if( index == S.size() ) {
            return NULL;
        }

        int depth = 0;
        int val = 0;

        int prevIndex = index;
        while( index<S.size() && S[index] == '-' ) {
            depth++;
            index++;
        }

        if( depth != expectDepth ) {
            index = prevIndex;
            return NULL;
        }

        while( index<S.size() && S[index] != '-' ) {
            val = 10*val + S[index] - '0';
            index++;
        }

        TreeNode* node = new TreeNode(val);
        node->left = recover(S, index, depth+1);
        node->right = recover(S, index, depth+1);
        return node;
    }
};