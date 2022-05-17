class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();

        if( n*m == 0 ) {
            return n+m;
        }

        int dp[n+1][m+1];

        for( int i=0; i<n+1; i++ ) {
            dp[i][0] = i;
        }

        for( int j=0; j<m+1; j++ ) {
            dp[0][j] = j;
        }

        for( int i=1; i<n+1; i++ ) {
            for( int j=1; j<m+1; j++ ) {
                int add = dp[i][j-1] +1;
                int del = dp[i-1][j] +1;
                int change = dp[i-1][j-1] +1;
                if( word1[i-1] == word2[j-1] ) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = min( min(add, del), change );
                }
            }
        }

        return dp[n][m];
    }
};