class Solution {
public:
    int numWays(int n) {
        vector<long> dp(101);
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;

        for( int i=3; i<=n; i++ ) {
            dp[i] = dp[i-2]%1000000007 + dp[i-1]%1000000007;
        }

        return dp[n]%1000000007;
    }
};