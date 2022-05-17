class Solution {
public:
    bool isPalindrome(int x) {
        if( x <0 ) {
            return false;
        }

        int dev = 1;
        while( x/dev >= 10 ) {
            dev *= 10;
        }

        while( x>0 ) {
            int left = x/dev;
            int right =x%10;
            if( left != right ) {
                return false;
            }

            x = (x%dev)/10;
            dev /= 100;
        }
        
        return true;

    }
};