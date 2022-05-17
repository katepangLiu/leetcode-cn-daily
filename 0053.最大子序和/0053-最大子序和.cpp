class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSub = INT_MIN;
        int dp(0);

        for( int i = 0; i<nums.size(); i++ ){
            dp = max( dp + nums[i], nums[i] );
            maxSub = max( maxSub, dp );
        }
        
        return maxSub;
    }
};