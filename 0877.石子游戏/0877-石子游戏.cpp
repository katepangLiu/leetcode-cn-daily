class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp( n, vector<int>(n));
        vector<int> preSum( n+1 );
        for( int i=0; i<n; i++ ) {
            preSum[i+1] = preSum[i] + piles[i];
        }

        for( int d=0; d<n; d++ ) {
            for( int i=0; i<n-d; i++ ) {
                int j = i+d;
                if( d == 0 ) {
                    dp[i][j] = piles[i];
                } else if( d == 1 ) {
                    dp[i][j] = max( piles[i], piles[j]);
                } else {
                    int rangeSumExcludeI = preSum[j+1] - preSum[i+1];
                    int rangeSumExcludeJ = preSum[j] - preSum[i];
                    dp[i][j] = max( rangeSumExcludeI-dp[i+1][j]+piles[i], rangeSumExcludeJ - dp[i][j-1] + piles[j] );
                }
            }
        }

        return dp[0][n-1] >  (preSum[n] - dp[0][n-1]) ;
    }
};