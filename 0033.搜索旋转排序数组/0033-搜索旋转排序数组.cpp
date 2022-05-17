class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if( n == 0 ) {
            return -1;
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
            } else {
                if( nums[l] <= target && target <= nums[mid-1] ) {
                    r = mid - 1;
                } else {
                    l = mid;
                }
            }
        }

        if( nums[l] == target ) {
            return l;
        }
        return -1;
    }
};