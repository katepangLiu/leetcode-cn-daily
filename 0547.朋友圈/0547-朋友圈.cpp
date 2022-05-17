class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size();
        vector<int> U(n);
        for( int i=0; i<n; i++ ) {
            U[i] = i;
        }

        for( int x=0; x<n; x++ ) {
            for( int y=x+1; y<n; y++ ) {
                if( M[x][y] == 0 ) {
                    continue;
                }

                int u1 = find(U, x);
                int u2 = find(U, y);
                if( u1 != u2 ) {
                    U[u1] = u2;
                }
            }
        }

        int ans = 0;
        for( int x=0; x<n; x++ ) {
            if( U[x] == x ) {
                ans ++;
            }
        }

        return ans;
    }

    int find(vector<int>& U, int n) {
        while( n != U[n] ) {
            n = U[n];
        }
            
        return n;
    }
};