class Solution {
public:
    double myPow(double x, int n) {
        if( n == 0 ) {
            return 1;
        }

        if( x == 0 || x == 1 ) {
            return x;
        }

        long N = n;
        if( n<0 ) {
            x = 1/x;
            N = -N;
        }

        return myPowCore(x, N);
    }

    double myPowCore(double x, long n) {
        double sub = x;
        double ans = 1.0;

        while( n>0 ) {
            if( n%2 == 1 ) {
                ans *= sub;
            }
                
            sub *= sub;
            n /= 2 ;
        }

        return ans;
    }
};