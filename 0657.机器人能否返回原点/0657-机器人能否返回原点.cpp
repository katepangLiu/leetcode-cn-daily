class Solution {
public:
    bool judgeCircle(string moves) {
        int leftOffset = 0;
        int upOffset = 0;

        for( char move : moves ) {
            if( 'L' == move ){
                leftOffset++;
            } else if( 'R' == move ) {
                leftOffset--;
            } else if( 'U' == move ) {
                upOffset++;
            } else if( 'D' == move ) {
                upOffset--;
            }
        }

        return leftOffset==0 && upOffset==0 ;
    }
};