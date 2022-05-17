class Solution {
public:
    static constexpr int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int xs;
    int ys;
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        xs = matrix.size();
        if( xs == 0 ) {
            return 0;
        }
        ys = matrix[0].size();
        vector<vector<int>> memo(xs, vector<int>(ys));
        int ans = 0;

        for( int x=0; x< xs; x++ ) {
            for( int y=0; y<ys; y++ ) {
                dfs( matrix, x, y, memo);
                ans = max( memo[x][y], ans);
            }
        }
        return ans;
    }

    int dfs(vector<vector<int>>& matrix, int x, int y, vector<vector<int>>& memo) {
        if( memo[x][y] != 0 ) {
            return memo[x][y];
        }
        memo[x][y]++;

        for( int i=0; i<4; i++ ) {
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            if( isValid(nx, ny) && matrix[nx][ny] >  matrix[x][y]) {
                memo[x][y] = max( memo[x][y], dfs( matrix, nx, ny, memo) + 1 );
            }
        }

        return memo[x][y];
    }

    bool isValid(int x, int y) {
        if( x >=0 && x<xs && y>=0 && y<ys ) {
            return true;
        }
        return false;
    }
};