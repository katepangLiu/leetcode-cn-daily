class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        if( n == 0 ) {
            return false;
        }
        int l = 0;
        int r = n-1;
        
        while( l < r ) {
            int mid = l + (r-l+1)/2;

            if( nums[mid] < nums[r] ) {
                if( nums[mid] <= target && target <= nums[r] ) {
                    l = mid;
                } else {
                    r = mid - 1;
                }
            } else if( nums[mid] > nums[r] ) {
                if( nums[l] <= target && target <= nums[mid-1] ) {
                    r = mid - 1;
                } else {
                    l = mid;
                }
            } else {
                if( nums[r] == target ) {
                    return true;
                }
                r--;
            }
        }

        if( nums[l] == target ) {
            return true;
        }
        return false;
    }
};