const int dirs[4][2] = { {-1,0}, {0, 1}, {1, 0}, {0, -1} };

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<bool>> visited( m, vector<bool>(n) );
        queue< tuple<int, int, int> > Q;
        int freshCount = 0;
        int maxDepth = 0;

        for( int x=0; x<m; x++ ) {
            for( int y=0; y<n; y++ ) {
                if( grid[x][y] == 2 ) {
                    Q.push( {0, x, y} );
                }
                if( grid[x][y] == 1 ) {
                    freshCount++;
                }
            }
        }


        while( !Q.empty() ) {
            int depth = 0;
            int x=0;
            int y =0;
            tie(depth, x ,y) = Q.front();
            Q.pop();
            maxDepth = max( maxDepth, depth);
            //cout << x << ',' << y << endl;

            for( int i=0; i<4; i++ ) {
                int nx = x + dirs[i][0];
                int ny = y + dirs[i][1];
                int nDepth = depth+1;
                //cout << nx << ',' << ny << endl;

                if( nx >=0 && nx <m && ny>=0 && ny<n ) {
                    //cout << visited[nx][ny] << ',' << grid[nx][ny]  << endl;
                    if( !visited[nx][ny] && grid[nx][ny] == 1 ) {
                        //cout << "Q.push" << endl;
                        visited[nx][ny] = true;
                        freshCount--;
                        Q.push( {nDepth, nx, ny} );
                    }
                }
            }
        } 

        return freshCount == 0 ? maxDepth : -1;
    }
};