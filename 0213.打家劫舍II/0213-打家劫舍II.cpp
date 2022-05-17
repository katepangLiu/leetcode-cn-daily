class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if( n == 0 ) {
            return 0;
        }
        if( n == 1 ) {
            return nums[0];
        }

        vector<vector<int>> gain(2, vector<int>(n) );
        gain[0][0] = nums[0];
        gain[0][1] = max(nums[0], nums[1]);
        gain[1][0] = 0;
        gain[1][1] = nums[1];

        for( int i=2; i<n; i++) {
            gain[0][i] = max(gain[0][i-1], gain[0][i-2] + nums[i] );
            gain[1][i] = max(gain[1][i-1], gain[1][i-2] + nums[i] );
        }


        return max( gain[0][n-2], gain[1][n-1] );
    }
};