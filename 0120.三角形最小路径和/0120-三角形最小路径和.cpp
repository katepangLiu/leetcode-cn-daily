class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int ans = INT_MAX;
        int n = triangle.size();
        if( n == 0 ) {
            return 0;
        }

        for( int i=1; i<n; i++ ) {
            for( int j=0; j<=i; j++ ) {
                if( j == 0 ) {
                    triangle[i][j] += triangle[i-1][j] ;
                } else if( j == i ){
                    triangle[i][j] += triangle[i-1][j-1];
                } else {
                    triangle[i][j] += min(triangle[i-1][j], triangle[i-1][j-1]);
                }
            }
        }

        for( int j=0; j<n; j++ ) {
            ans = min( ans, triangle[n-1][j] );
        }

        return ans;
    }
};