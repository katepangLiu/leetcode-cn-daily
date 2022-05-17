class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int n = nums.size();
        int updateCount = 0; 
        if( n == 0 ) {
            return 0;
        }

        vector<long> top3Vec(3, LONG_MIN);
        for( int num : nums ) {
            if( num > top3Vec[0] ) {
                top3Vec[2] = top3Vec[1];
                top3Vec[1] = top3Vec[0];
                top3Vec[0] = num;
                updateCount++;
            } else if ( num == top3Vec[0]) {
                continue;
            } else if( num > top3Vec[1] ) {
                top3Vec[2] = top3Vec[1];
                top3Vec[1] = num;
                updateCount++;
            } else if( num == top3Vec[1] ) {
                continue;
            } else if( num >= top3Vec[2] ) {
                top3Vec[2] = num;
                updateCount++;
            } 
        }

        return top3Vec[2] != LONG_MIN ?  top3Vec[2] : top3Vec[0]  ;
    }
};