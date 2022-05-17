typedef long long ll;
const int MOD=1000000000+7;

class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        
        ll f[15][15][2] = {0};
        
        int m = grid.size();
        int n = grid[0].size();
        f[0][0][0] = grid[0][0];
        f[0][0][1] = grid[0][0];
        for( int i=1; i<m; i++ ) {
            f[i][0][0] = f[i][0][1] = (f[i-1][0][0]*grid[i][0]);
        }
        
        for( int j=1; j<n; j++ ) {
            f[0][j][0] = f[0][j][1] = f[0][j-1][0]*grid[0][j]; 
            
        }
        
        for( int i=1; i<m; i++ ) {
            for( int j=1; j<n; j++ ) {
                
                if( grid[i][j] == 0 ) {
                    f[i][j][0] = 0;
                    f[i][j][1] = 0;
                    continue;
                }
            
                f[i][j][0] = max4( f[i][j-1][0]*grid[i][j]
                , f[i-1][j][0]*grid[i][j]
                , f[i][j-1][1]*grid[i][j]
                , f[i-1][j][1]*grid[i][j]);

                f[i][j][1] = min4( f[i][j-1][0]*grid[i][j]
                , f[i-1][j][0]*grid[i][j]
                , f[i][j-1][1]*grid[i][j]
                , f[i-1][j][1]*grid[i][j]);
    
                cout << i << ',' << j << ':' << f[i][j][0] << ',' <<f[i][j][1] << endl;
                
             }
        }
        
        return f[m-1][n-1][0] >= 0 ? f[m-1][n-1][0]%MOD : -1 ;
    }

    ll max4( ll a, ll b, ll c , ll d ) {
        ll tmp1 = max(a, b);
        ll tmp2 = max(c, d);
        return max(tmp1, tmp2);
    }

    ll min4( ll a, ll b, ll c , ll d ) {
        ll tmp1 = min(a, b);
        ll tmp2 = min(c, d);
        return min(tmp1, tmp2);
    }
};