class Solution {
    public int integerBreak(int n) {
        int[] f = new int[n+1];
        for( int i=2; i<=n; i++ ) {
            for( int j=1; j<=i; j++ ) {
                int tmp = Math.max( j*(i-j), j*f[i-j]);
                f[i] = Math.max(f[i], tmp);
            }
        }
        return f[n];
    }
}