const int dirs[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

class Solution {
public:
    int m;
    int n;    
public:
    void solve(vector<vector<char>>& board) {
        if( board.size() == 0 || board[0].size() == 0 ) {
            return;
        }
        m = board.size();        
        n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n));
        
        for( int x=0; x<m; x++ ) {
            for( int y=0; y<n; y++ ) {
                if( (x == 0) || (x == m-1) || (y == 0) || (y == n-1) ) {
                    dfs(board, visited, x, y);
                }
            }
        }

        for( int x=0; x<m; x++ ) {
            for( int y=0; y<n; y++ ) {
                if( board[x][y] == 'O' ) {
                    board[x][y] = 'X' ;
                } else if( board[x][y] == 'M' ) {
                    board[x][y] = 'O';
                }
            }
        }
    }

    void dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, int x, int y) {
        if( board[x][y] == 'X' ) {
            return;
        }
        if( board[x][y] == 'M' ) {
            return;
        }

        visited[x][y] = true;
        board[x][y] = 'M';
        for( int i=0 ;i<4; i++ ) {
            int nx = x + dirs[i][0];
            int ny = y + dirs[i][1];
            if( nx >=0 && nx <m && ny>=0 && ny<n && !visited[nx][ny]) {
                dfs(board, visited, nx, ny);
            }
        }
        visited[x][y] = false;
    }
};