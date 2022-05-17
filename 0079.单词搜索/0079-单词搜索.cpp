class Solution {
public:
    int dirs[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0,-1} };
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> vis( m, vector<bool>(n) ); 

        for( int x=0; x<m; x++ ) {
            for( int y=0; y<n; y++ ) {
                if( dfs( board, vis, x, y, word, 0) ) {
                    return true;
                }
            }
        }

        return false;
    }

    bool dfs(vector<vector<char>>& board, vector<vector<bool>>& vis, int x, int y, string& word, int index ) {
        if( board[x][y] != word[index] ) {
            return false;
        }

        if( index == word.size() -1 ) {
            return true;
        }

        vis[x][y] = true;
        int m = board.size();
        int n = board[0].size();
        for( int i=0; i<4; i++ ) {
            int nx = x + dirs[i][0];
            int ny = y + dirs[i][1];
            if( nx >=0 && nx < m && ny>=0 && ny < n && !vis[nx][ny] ) {
                if(dfs( board, vis, nx, ny, word, index+1 )) {
                    return true;
                }
            }
        } 
        vis[x][y] = false;
        return false;
    }
};