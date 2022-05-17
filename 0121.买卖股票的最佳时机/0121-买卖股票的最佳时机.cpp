class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int last = 0;
       int profit = 0;

        if( prices.size() <2 ){
            return 0;
        }
 
        for( int i=0; i< prices.size()-1; i++ ){
            last = max( 0, last+prices[i+1] - prices[i] );
            profit = max( profit, last );
        }

        return profit;
    }
};