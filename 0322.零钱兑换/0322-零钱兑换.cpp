class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> f(amount+1, -1);
        f[0] = 0;
        for( int i=1; i<= amount; i++ ) {
            for( auto coin : coins ) {
                if( i >= coin && f[i-coin]>=0 ) {
                    if( f[i] == -1 ) {
                        f[i] = f[i-coin] + 1;
                    } else {
                        f[i] = min(f[i], f[i-coin]+1);
                    }
                }
            }
        }
        return f[amount];
    }
};