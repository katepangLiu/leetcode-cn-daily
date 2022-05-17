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

        vector<int> gain(n, 0);

        gain[0] = nums[0];
        gain[1] = max(nums[0], nums[1]);
        for( int i=2; i<n; i++ ) {
            gain[i] = max(gain[i-1], gain[i-2]+nums[i]);
        }

        return gain[n-1];
    }
};