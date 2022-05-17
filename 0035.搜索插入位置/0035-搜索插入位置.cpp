class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        if( n == 0 ) {
            return 0;
        }

        if( nums[0] > target ) {
            return 0;
        }
        if( nums[n-1] < target ) {
            return n;
        }

        int l = 0;
        int r = n-1;
        //����ѡ��:  >,�ų������б�target�������;
        while( l < r ) {
            int mid = l + (r-l+1)/2;
            if( nums[mid] > target ) {
                r = mid-1;
            } else {
                l = mid;
            }
        }
        if( nums[l] == target ) {
            return l;
        }
        return l+1;
    }
};