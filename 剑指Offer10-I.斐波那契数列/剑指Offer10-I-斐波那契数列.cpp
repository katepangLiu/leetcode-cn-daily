class Solution {
public:
    int fib(int n) {
        int a[2] = {0};
        a[1] = 1;
        int sum = 0;

        if( n <2 ){
            return a[n];
        }

        for( int i =2; i<= n; i++ ){
            sum = (a[0]+a[1])%1000000007;
            a[0] = a[1];
            a[1] = sum;
        }

        return a[1];
        
    }
};