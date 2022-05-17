/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    map<Node*, Node*> memo;    
public:
    Node* cloneGraph(Node* node) {
        if( node == nullptr ) {
            return nullptr; 
        }

        if( memo.find(node) != memo.end() ) {
            return memo[node];
        }

        Node* newNode = new Node(node->val);
        memo[node] = newNode;

        int n = node->neighbors.size();
        newNode->neighbors.resize(n);
        for( int i=0; i<n; i++ ) {
            newNode->neighbors[i] = cloneGraph(node->neighbors[i]);
        }

        return newNode;
    }
};