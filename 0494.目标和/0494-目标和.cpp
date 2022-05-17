class Solution {
public:
    int ans;    
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        if( nums.size() == 0 ) {
            return 0;
        }
        ans = 0;
        backtrace(nums, S, 0);
        return ans;
    }

    void backtrace(vector<int>& nums, long long S, int i) {
        if( i == nums.size() ) {
            if( S == 0 ) {
                ans++;
            }
            return;
        }

        backtrace(nums, S-nums[i], i+1);
        backtrace(nums, S+nums[i], i+1);
    }

};