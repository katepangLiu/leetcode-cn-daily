class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        //DFS
        //return dfs(n);  

        //DP
        if( n == 0 ) {
            return 1;
        } 
        if( n == 1 ) {
            return 10;
        }
        if( n > 10 ) {
            n = 10;
        }

        int dp[11] = {0};
        dp[0] = 1;
        dp[1] = 9; 
        int count = dp[0] + dp[1];

        for( int i=2; i<=n; i++ ) {
            dp[i] = dp[i-1]*(10-(i-1));
            count += dp[i];
        }

        return count;
    }

    int dfs(int n) {
        if( n == 0 ) {
            return 1;
        }
        if( n == 1 ) {
            return 10;
        }
        if( n>=10 ) {
            return dfs(10);
        }

        return (dfs(n-1) - dfs(n-2))*(11-n) + dfs(n-1);
    }
};