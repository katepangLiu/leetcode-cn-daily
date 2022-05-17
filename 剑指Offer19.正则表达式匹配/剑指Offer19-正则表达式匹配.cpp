class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length();
        int n = p.length();
        vector<vector<bool>> dp( m+1, vector<bool>(n+1) );
        for( int i=0; i<=m; i++ ) {
            for( int j=0; j<=n; j++ ) {
                if( j == 0 ) {
                    dp[i][j] = i==0 ;
                } else {
                    if( p[j-1] != '*' ) {
                        if( i == 0 ) {
                            dp[i][j] = false;
                        } else {
                            if( s[i-1] == p[j-1] || p[j-1] == '.' ) {
                                dp[i][j] = dp[i-1][j-1];
                            }
                        }
                    } else {
                        //�� x* ƥ��0�Σ�ƥ��n�� �������;
                        if( j>=2 ) {
                            dp[i][j] = dp[i][j-2];
                        }

                        if( i>=1 && j>=2 && (s[i-1] == p[j-2] || p[j-2] == '.') ) {
                            dp[i][j] = dp[i][j-2] || dp[i-1][j];
                        }
                    } 
                }
            } 
        }

        return dp[m][n];
    }
};