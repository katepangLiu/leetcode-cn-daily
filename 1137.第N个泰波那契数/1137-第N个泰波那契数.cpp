class Solution {
public:
    int tribonacci(int n) {
        int dp[3] = {0, 1, 1};
        if( n<3 ) {
            return dp[n];
        }

        for( int i=3; i<=n; i++ ) {
            int tmp = dp[2];
            dp[2] = dp[0] + dp[1] + dp[2];
            dp[0] =dp[1];
            dp[1] = tmp;
        }

        return dp[2];
    }
};