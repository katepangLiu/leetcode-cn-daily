/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if( !root || (!root->left && !root->right) ) {
            return root;
        }

        if( root->left && root->right ) {
            root->left->next = root->right;
            root->right->next = getNextNotNullChild(root);
        }else if (root->left) {
            root->left->next = getNextNotNullChild(root);
        }else {
            root->right->next = getNextNotNullChild(root);
        }

        root->right = connect(root->right);
        root->left = connect(root->left);
        return root;
    }

    Node* getNextNotNullChild( Node* root ) {
        if( !root ){
            return NULL;
        }
        while( root->next ) {
            if( root->next->left ) {
                return root->next->left;
            }
            if( root->next->right ) {
                return root->next->right;
            }
            root = root->next;
        }
        return NULL;
    }
};