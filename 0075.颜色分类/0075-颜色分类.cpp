class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = n-1;
        for( int i=0; i<=r; i++ ) {
            if( nums[i] == 0 ) {
                nums[i] = nums[l];
                nums[l] = 0;
                l++;
            }
            if( nums[i] == 2 ) {
                nums[i] = nums[r];
                nums[r] = 2;
                r--;
                i--;
            }
        }

        return;
    }
};