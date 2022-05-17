/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *left;
 *     struct Node *right;
 *     struct Node *next;
 * };
 */

void dfs(struct Node* root, struct Node* next) {
    if( !root ) {
        return;
    }

    root->next = next;
    dfs( root->left, root->right );
    dfs( root->right, root->next ? root->next->left : NULL );
}

struct Node* connect(struct Node* root) {
	dfs( root, NULL );
    return root;
}