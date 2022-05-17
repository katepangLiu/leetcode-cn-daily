class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int count = 0;
        
        for( int x=0; x<m; x++ ) {
            for( int y=0; y<n; y++ ) {
                if( mat[x][y] == 1 ) {
                    bool vaild = true;
                    for( int i=0; i<m; i++ ) {
                        if( i == x ) {
                            continue;
                        }
                        if( mat[i][y] != 0 ) {
                            vaild = false;
                            break;
                        }
                    }
                    
                    if( vaild == false ) {
                        continue;
                    }
                    
                    for( int j=0; j<n; j++ ) {
                        if( j == y ) {
                            continue;
                        }
                        if( mat[x][j] !=0 ) {
                            vaild = false;
                            break;
                        }
                    }
                    
                    if( vaild == true ) {
                        count++;
                    }
                }
            }
        }
        
        return count;
    }
};