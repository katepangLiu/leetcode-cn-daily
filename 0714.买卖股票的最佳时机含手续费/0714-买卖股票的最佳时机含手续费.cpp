class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int cash = 0, hold = -prices[0];
        int n = prices.size();
        for( int i=1; i<n; i++ ) {
            hold = max( hold, cash-prices[i] );
            cash = max( cash, hold+prices[i]-fee );
        }

        return cash;
    }
};