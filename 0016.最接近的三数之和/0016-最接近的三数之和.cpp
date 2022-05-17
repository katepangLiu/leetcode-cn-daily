class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = nums[0]+nums[1]+nums[2];
        int midDiff = abs(ans-target);
        if( ans == target ) {
            return target;
        }
        int end = false;

        for( int i=0; i<n; i++ ) {
            int subTarget = target - nums[i];
            int l = i+1;
            int r = n-1;
            while( l<r ) {
                int sum = nums[l] + nums[r];
                int diff = sum - subTarget;
                if( abs(diff) < midDiff ) {
                    midDiff = abs(diff);
                    ans = sum + nums[i];
                }

                if( diff == 0 ) {
                    return target;
                } else if( diff < 0 ) {
                    l++;
                } else {
                    r--;
                }
            }
        }

        return ans;
    }
};