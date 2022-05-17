class Solution {
public:
    bool divisorGame(int N) {
        vector<int> dp(N+1);
        dp[0] = false;
        dp[1] = false;
        for( int i=2; i<=N; i++ ) {
            for( int j=1; j<i; j++ ) {
                if( i%j == 0 && dp[i-j] == false ) {
                    dp[i] = true;    
                }
            }
        }

        return dp[N];
    }
};