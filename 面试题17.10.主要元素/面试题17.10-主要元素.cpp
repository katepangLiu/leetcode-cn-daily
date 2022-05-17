class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        if( n == 0 ) {
            return -1;
        }

        int count =0;
        int ans = 0;
        for( int num : nums ) {
            if( count == 0 ) {
                ans = num;
                count++;
            } else {
                if( ans == num ) {
                    count++;
                } else {
                    count--;
                }
            }
        }

        if( count <= 0 ) {
            return -1;
        }

        count = 0;
        for( int num : nums ) {
            if( ans == num ) {
                count++;
            }
        }
        return count > n/2 ? ans : -1 ;
    }
};