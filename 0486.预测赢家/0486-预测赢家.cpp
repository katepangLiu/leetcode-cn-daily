class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        //[l...r]
        //ѡl   score[l...r] = sum[l+1...r] - score[l+1...r] + nums[l] ;
        //ѡr   score[l...r] = sum[l...r-1] - score[l...r-1] + nums[r] ;

        int n = nums.size();
        vector<int> preSum(n+1);
        for(int i=0; i<n; i++) {
            preSum[i+1] = preSum[i]+nums[i];
        }
        vector<vector<int>> dp(n , vector<int>(n));

        for( int diff=0; diff<n; diff++) {
            for( int i=0; i<n-diff; i++ ) {
                int j = i+diff;
                if( diff == 0 ) {
                    dp[i][j] = nums[i];
                } else if( diff == 1 ) {
                    dp[i][j] = max( nums[i], nums[j]); 
                } else {
                    int rangeSumWithOutI = preSum[j+1] - preSum[i+1] ; 
                    int rangeSumWithoutJ = preSum[j] - preSum[i];
                    dp[i][j] = max( rangeSumWithOutI-dp[i+1][j] +nums[i] , rangeSumWithoutJ-dp[i][j-1]+nums[j] );
                }
                //cout << i << ',' << j << ':' << dp[i][j] << endl;
            }
        }

        return dp[0][n-1] >= (preSum[n]-dp[0][n-1]);
    }
};