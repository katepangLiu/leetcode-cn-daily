class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size();
        int n = s2.size();
        int l = s3.size();
        
        if( l != m+n ) {
            return false;
        }

        vector<vector<bool>> dp(m+1, vector<bool>(n+1));

        for( int i=0; i<m+1; i++ ) {
            for( int j=0; j<n+1; j++ ) {
                int idx1 = i-1;
                int idx2 = j-1;
                int idx3 = i+j-1;

                if( i == 0 && j== 0 ) {
                    dp[i][j] = true;
                }
                else if( i == 0 ) {
                    dp[i][j] = dp[i][j-1] && s2[idx2] == s3[idx3];
                }
                else if( j == 0 ) {
                    dp[i][j] = dp[i-1][j] && s1[idx1] == s3[idx3];
                }
                else {
                    dp[i][j] = (dp[i-1][j] && s1[idx1] == s3[idx3]) || (dp[i][j-1] && s2[idx2] == s3[idx3] ) ; 
                }
                //cout << i << "," << j << ":" << dp[i][j] << endl;
            }
        }

        return dp[m][n];
    }
};