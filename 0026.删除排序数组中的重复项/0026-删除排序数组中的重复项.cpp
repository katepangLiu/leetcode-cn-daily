class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if( n<=0 ) {
            return 0;
        }

        int len = 1;
        int last = 0;
        for( int i=1; i<n; i++ ) {
            if( nums[last] == nums[i] ) {
                continue;
            }

            nums[len] = nums[i];
            len++;
            last=i;
        }

        return len;
    }
};