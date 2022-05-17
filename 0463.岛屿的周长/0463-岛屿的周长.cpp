class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        //基本思路: 
        //如果一条边上的2个格子：一个地一个水，则这是岛屿的一个边
        //边界需要特殊处理;
        //累计

        int m = grid.size();
        if( m == 0 ) {
            return 0;
        }
        int n = grid[0].size();
        int perimeter = 0;

        for( int x=0; x< n; x++ ) {
            for( int i=0; i< m+1; i++ ) {
                //cout << i << x << endl;
                int left = (i-1 >= 0) ? grid[i-1][x] : 0 ;
                int right = (i < m) ? grid[i][x] : 0;
                perimeter += left^right;
            }
        }
        for( int y=0; y<m; y++ ) {
            for( int i=0; i< n+1; i++ ) {
                //cout << i << y << endl;
                int up = (i-1 >= 0) ? grid[y][i-1] : 0 ;
                int down = (i < n) ? grid[y][i] : 0;
                perimeter += up^down;
            }
        }

        return perimeter;
    }
};