class Solution {
public:
    int translateNum(int num) {
        //vector<vector<int>> (2, vector<int>(32));
        vector<int> dp(32);
        dp[0] = 1;
        dp[1] = 1;
        
        int cur = num%10;
        int prev = cur;
        num = num/10;
        int i = 2;

        while( num ) {
            int cur = num%10;
            num /=10;
            dp[i] = dp[i-1];
            if( (cur ==2 && prev>=0 && prev<6) || (cur==1) ) {
                dp[i]+= dp[i-2];
            }
            prev = cur;
            i++;
        }

        return dp[i-1];    
    }
};