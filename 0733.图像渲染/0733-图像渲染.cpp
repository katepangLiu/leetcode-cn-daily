const int dir[4][2] = { {-1,0}, {0, 1}, {1, 0}, {0, -1} };
class Solution {
public:
    int rs;
    int cs;    
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {    
        rs = image.size();
        cs = image[0].size();
        vector<vector<bool>> visited(rs, vector<bool>(cs));
        int oldColor = image[sr][sc];
        if( oldColor == newColor ) {
            return image;
        }

        dfs(image, visited, sr, sc, oldColor, newColor);
        return image;
    }

    void dfs(vector<vector<int>>& image, vector<vector<bool>>& visited, int r, int c, int oldColor, int newColor) {
        if( image[r][c] != oldColor ) {
            return;
        }

        visited[r][c] = true;
        image[r][c] = newColor;

        for( int i=0; i<4; i++ ) {
            int nr = r + dir[i][0];
            int nc = c + dir[i][1];
            if( nr >= 0 && nr < rs && nc >=0 && nc<cs && !visited[nr][nc] ) {
                dfs(image, visited, nr, nc, oldColor, newColor);
            }
        }

        visited[r][c] = false;
    }
};