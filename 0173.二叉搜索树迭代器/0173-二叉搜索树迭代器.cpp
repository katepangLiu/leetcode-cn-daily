/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    stack<TreeNode*> st; 
public:
    BSTIterator(TreeNode* root) {
        leftDFS(root);
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode* node = st.top();
        st.pop();
        leftDFS(node->right);
        return node->val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !st.empty();
    }

    void leftDFS(TreeNode* root) {
        if( !root ) {
            return;
        }

        st.push(root);
        leftDFS(root->left);
    }

};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */