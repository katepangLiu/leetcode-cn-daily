class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int newIndxe = 0;
        int count = 0;
        int n = nums.size();
        if( n == 0 ) {
            return 0;
        }
        if( n == 1 || n== 2 ) {
            return n;
        }

        newIndxe ++;
        count++;
        int prevNum = nums[0];

        for( int i=1; i<n; i++ ) {
            if( nums[i] == prevNum ) {
                count++;
            } else {
                count = 1;
                prevNum = nums[i];
            }
            if( count <3 ) {
                nums[newIndxe]= nums[i];
                newIndxe++;
            }
        }

        return newIndxe;
    }
};