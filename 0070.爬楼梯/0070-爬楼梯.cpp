class Solution {
public:
    int climbStairs(int n) {
        int dp[2] = {1, 2};
        if( n ==1 ) {
            return dp[0];
        }
        if( n == 2 ) {
            return dp[1];
        }

        for( int i=2; i<n; i++ ) {
            int tmp = dp[1];
            dp[1] = dp[0]+dp[1];
            dp[0] = tmp;
        }

        return dp[1];
    }
};