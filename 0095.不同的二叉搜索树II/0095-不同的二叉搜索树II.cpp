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
    vector<TreeNode*> generateTrees(int n) {
        if( n == 0 ) {
            return {};
        }

        return generate(1, n);
    }

    vector<TreeNode*> generate( int start, int end ) {
        if( start > end ) {
            return {nullptr};
        }

        vector<TreeNode*> trees;
        for( int i=start; i<=end; i++ ) {
            vector<TreeNode*> lefts = generate(start, i-1);
            vector<TreeNode*> rights = generate(i+1, end);

            for( auto left : lefts ) {
                for( auto right : rights ) {
                    TreeNode* tree = new TreeNode(i);
                    tree->left = left;
                    tree->right = right;
                    trees.emplace_back(tree);
                }
            }
        }

        return trees;
    }

};