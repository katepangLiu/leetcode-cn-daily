struct Node{
    vector<Node*> childrens;
    bool isEnd;
    Node() : childrens(26), isEnd(false) {};
};

const int dir[4][2] = { {0, -1}, {1, 0}, {0, 1}, {-1, 0} };

class Solution {
public:
    vector<string> ans;
    Node Tire;
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        buildTire(words);
        
        string tmpWord = "";
        for( int x=0; x<m; x++ ) {
            for( int y=0; y<n; y++ ) {
                backtrace(board, visited, x, y, &Tire, tmpWord );
            }
        }
        return ans;
    }

    void backtrace(vector<vector<char>>& board, vector<vector<bool>>& visited, int x, int y, Node* pTireNode, string tmpWord) {
        tmpWord.push_back(board[x][y]);
        int ich = board[x][y] - 'a';
        if(!pTireNode->childrens[ich]) {
            return ;
        }
        pTireNode = pTireNode->childrens[ich];
        if( pTireNode->isEnd ) {
            ans.push_back(tmpWord);
            pTireNode->isEnd = false;//保证所有单词只出现一次;
        }

        visited[x][y] = true;

        for( int i =0; i<4; i++ ) {
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            if( needAccess(board, visited, nx, ny) ) {
                backtrace(board, visited, nx, ny, pTireNode, tmpWord);
            }
        }

        visited[x][y] = false; 
    }

    bool needAccess(vector<vector<char>>& board, vector<vector<bool>>& visited, int x, int y) {
        int m = board.size();
        int n = board[0].size();
        if( x >=0 && x<m && y>=0 && y<n && !visited[x][y]) {
            return true;
        }
        return false;
    }

    void buildTire(vector<string>& words) {
        for( auto word : words ) {
            addWord(word);
        }
    }

    void addWord(string& word) {
        Node* pNode = &Tire;
        for( auto& ch : word ) {
            int ich = ch - 'a';
            if( !pNode->childrens[ich] ) {
                pNode->childrens[ich] = new Node();
            }
            pNode = pNode->childrens[ich];
        }
        pNode->isEnd = true;
    }
};