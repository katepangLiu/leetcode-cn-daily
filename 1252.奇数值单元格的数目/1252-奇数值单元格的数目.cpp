class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        int ans = 0;

        vector<int> row(m);
        vector<int> col(n);

        for( int i=0; i<m; i++ ) {
            for( int j=0; j<indices.size(); j++ ) {
                if( indices[j][0] == i ) {
                    row[i]++;
                }
            }
        }

        for( int i=0; i<n; i++ ) {
            for( int j=0; j<indices.size(); j++ ) {
                if( indices[j][1] == i ) {
                    col[i]++;
                }
            }
        }

        for( int i=0; i<m; i++ ) {
            for( int j=0; j<n; j++ ) {
                int x = row[i] + col[j];
                if( x%2 ) {
                    ans++;
                }
            }
        }

        return ans;
    }
};