class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        if( n == 0 ) {
            return {-1, -1};
        }
        int start = 0;
        int end = n-1;
        int firstIndex = getFirstTargetIndex(nums, start, end, target);
        if( firstIndex == -1 ) {
            return {-1, -1};
        }
        int lastIndex = getLastTargetIndex(nums, start, end, target);
        return {firstIndex, lastIndex};
    }

    int getFirstTargetIndex(vector<int>& nums, int& start, int& end, int target) {
        int l = start;
        int r = end;
        while( l < r ) {
            int mid = l + (r-l)/2;
            if( nums[mid] < target ) {
                l = mid+1;
                start = l;
            } else {
                r = mid;
                if( nums[mid] != target ) {
                    end = r;
                }
            }
        }
        if( nums[l] == target ) {
            return l;
        }
        return -1;
    }

    int getLastTargetIndex( vector<int>& nums, int start, int end, int target) {
        int l = start;
        int r = end;
        while( l < r ) {
            int mid = l+(r-l+1)/2;;
            if( nums[mid] > target) {
                r = mid-1;
            } else {
                l = mid;
            }
        }
        if( nums[l] == target ) {
            return l;
        }
        return -1;
    }
};