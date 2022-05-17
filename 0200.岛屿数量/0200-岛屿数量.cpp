const int dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} }; 

class Solution {
public:
    int m;
    int n;
public:
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<int>> vis( m, vector<int>(n, false) );
        int count = 0;
        cout << m << ',' << n << endl;

        for( int x=0; x<m; x++ ) {
            for( int y=0; y<n; y++ ) {
                //cout << x << ',' << y << ',' << !vis[x][y] << ',' << grid[x][y] << endl;
                if( (!vis[x][y]) && (grid[x][y]=='1')) {
                    //cout << "valid" << endl;
                    count++;
                    dfs( grid, vis, x, y);
                }
            }
        }

        return count;
    }

    void dfs( vector<vector<char>>& grid,  vector<vector<int>>& vis, int x, int y) {
        //cout << x << ',' << y << endl;;

        vis[x][y] = true;
        for( int i=0; i<4; i++ ) {
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            if( nx>=0 && nx<m && ny>=0 && ny<n && !vis[nx][ny] && (grid[nx][ny] == '1') ) {
                dfs( grid, vis, nx, ny);
            }
        }
    }
};