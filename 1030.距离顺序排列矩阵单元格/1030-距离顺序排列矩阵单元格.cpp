class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<vector<int>> ans;
        for( int r=0; r<R; r++ ) {
            for( int c=0; c<C; c++ ) {
                ans.push_back( {r, c} );
            }
        }

        sort( ans.begin(), ans.end(), [=](vector<int>& a, vector<int>& b)  {
            return (abs( a[0]-r0 ) + abs( a[1] - c0 )) < (abs( b[0]-r0 ) + abs( b[1] - c0 ));
        }  );

        return ans;
    }
};