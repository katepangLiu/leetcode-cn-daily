struct Node {
    unordered_map<char, Node*> childrens;
    bool isEnd;
    Node() : isEnd(false) {};
};

class WordDictionary {
Node tire;
public:
    /** Initialize your data structure here. */
    WordDictionary() {
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        Node* pNode = &tire;
        for( auto& ch : word ) {
            if( pNode->childrens.count(ch) == 0 ) {
                pNode->childrens[ch] = new Node();
            }
            pNode = pNode->childrens[ch];
        }
        pNode->isEnd = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return search(word, 0, &tire);
    }

    bool search(string word, int start, Node* pNode) {
        for( int i = start; i<word.size(); i++ ) {
            if( word[i] == '.' ) {
                for( auto it = pNode->childrens.begin(); it!= pNode->childrens.end(); it++ ) {
                    if(search(word, i+1, it->second)) {
                        return true;
                    }
                }
                return false;
            } else {
                char ch = word[i];
                if( pNode->childrens.count(ch) == 0 ) {
                    return false;
                }
                pNode = pNode->childrens[ch];
            }
        }
        return pNode->isEnd;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */