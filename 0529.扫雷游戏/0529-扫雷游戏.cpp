const int dirs[8][2] = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};

class Solution {
public:
    int m;
    int n;    
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        m = board.size();
        n = board[0].size();

        int x = click[0];
        int y = click[1];

        if( !isVaildPos(x, y) ) {
            return board;
        }
 
        if( board[x][y] == 'M' ) {
            board[x][y] = 'X';
            return board;
        }

        vector<vector<bool>> visited( m, vector<bool>(n) );
        dfs(board, visited, x, y);
        return board;
    }

    void dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, int x, int y) {
        //周围有地雷则修改为相应的个数;
        int count = enumBomb(board, x, y);
        if( count > 0 ) {
            board[x][y] = '0' + count;
            return;
        }

        //周围没有地雷则修改为'B'
        visited[x][y] = true;
        board[x][y] = 'B';

        for( int i=0; i<8; i++ ) {
            int nx = x+dirs[i][0];
            int ny = y+dirs[i][1];
            if( isVaildPos(nx, ny) && !visited[nx][ny] && board[nx][ny] == 'E') {
                dfs(board, visited, nx, ny);
            }
        }
        visited[x][y] = false;
    }

    bool isVaildPos( int x, int y ) {
        if( x>=0 && x<m && y>=0 && y<n ) {
            return true;
        }

        return false;
    }

    int enumBomb(vector<vector<char>>& board, int x, int y) {
        int count = 0;
        
        for( int i=0; i<8; i++ ) {
            int nx = x+dirs[i][0];
            int ny = y+dirs[i][1];

            if( isVaildPos(nx,ny) && board[nx][ny] == 'M' ) {
                count++;
            }
        }
        return count;
    }
};