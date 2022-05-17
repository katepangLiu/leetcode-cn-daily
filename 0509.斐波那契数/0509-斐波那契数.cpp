class Solution {
public:
    int fib(int N) {
        int f[2] = {0, 1};
        int tmp = 0;

        if( N < 2 ) {
            return f[N];
        }

        for( int i=2; i<=N; i++ ) {
            tmp = f[1];
            f[1] = f[0] + f[1];
            f[0] = tmp;
        }

        return f[1];
    }
};