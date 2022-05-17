class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if( n<2 ) {
            return 0;
        }

        // f[i][0]: 手上持有股票的最大收益
        // f[i][1]: 手上不持有股票，并且处于冷冻期中的累计最大收益
        // f[i][2]: 手上不持有股票，并且不在冷冻期中的累计最大收益
        vector<vector<int>> f(n, vector<int>(3));
        f[0][0] = -prices[0];
        for (int i = 1; i < n; ++i) {
            //i天持有股票: i-1天持有，i天不操作; i-1天不持有且不冻结，i天买入; 
            f[i][0] = max( f[i-1][0], f[i-1][2] - prices[i] );
            //i天不持有股票且冻结：i-1天持有，i天卖出;
            f[i][1] = f[i-1][0] + prices[i];
            //i天不持有股票且不冻结：i-1天持有不冻结; i-1天持有不冻结;
            f[i][2] = max(f[i-1][2], f[i-1][1]);
        }
        return max( f[n-1][1], f[n-1][2]);
    }
};