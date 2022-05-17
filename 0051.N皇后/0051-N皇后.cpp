class Solution {
public:
    vector<vector<string>> ans;
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<char>> grid ( n, vector<char>(n, '.') ) ;
        backtrace( grid, n, 0 );
        return ans;
    }

    void backtrace( vector<vector<char>>& grid, int n, int x) {
        if( x == n ) {
            vector<string> tmp;
            for( auto row : grid ) {
                tmp.emplace_back( row.begin(), row.end() );
            }
            ans.push_back(tmp);
            return;
        }

        for( int y=0; y<n; y++ ) {
            if( isVaildPos(grid, n, x, y) ){
                grid[x][y] = 'Q';
                backtrace(grid, n, x+1);
                grid[x][y] = '.';
            }
        }
    }

    bool isVaildPos(vector<vector<char>>& grid, int n, int x, int y) {
        // 同一行
        for (int j = 0; j < y; j++) {
            if (grid[x][j] == 'Q') {
                return false;
            }
        }
        // 同一列
        for (int i = 0; i < x; i++) {
            if (grid[i][y] == 'Q') {
                return false;
            }
        }
        // 主对角线
        for (int i = x - 1, j = y - 1; i >= 0 && j >= 0; i--, j--) {
            if (grid[i][j] == 'Q') {
                return false;
            }
        }
        // 副对角线
        for (int i = x - 1, j = y + 1; i >= 0 && j < n; i--, j++) {
            if (grid[i][j] == 'Q') {
                return false;
            }
        }
        return true;        
    }
};