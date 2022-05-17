
struct Node {
    vector<Node*> child;
    bool isWord;
    Node(): child(26, NULL), isWord(false) {};
};

class Trie {

Node root;

public:
    /** Initialize your data structure here. */
    Trie() {
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* pNode = &root;
        for( char ch : word ) {
            int ich = ch - 'a';
            if( pNode->child[ich] == 0 ) {
                pNode->child[ich] = new Node();
            }
            pNode = pNode->child[ich];
        }
        pNode->isWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* pNode = &root;
        for( char ch : word ) {
            int ich = ch - 'a';
            if( pNode->child[ich] == 0 ) {
                return false;
            }
            pNode = pNode->child[ich];
        }
        return pNode->isWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node* pNode = &root;
        for( char ch : prefix ) {
            int ich = ch - 'a';
            if( pNode->child[ich] == 0 ) {
                return false;
            }
            pNode = pNode->child[ich];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */