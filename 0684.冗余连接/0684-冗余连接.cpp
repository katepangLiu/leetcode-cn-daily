class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> U(n+1);

        for( int i=0; i<n; i++ ) {
            U[i] = i;
        }

        for( auto& edge : edges ) {
            int u = find(U, edge[0]);
            int v = find(U, edge[1]);

            if( u == v ) {
                return edge;
            }

            U[u] = v;
        }

        return {0, 0};
    }

    int find(vector<int>& U, int u) {
        while( U[u] != u ) {
            u = U[u];
        }
        return u;
    }
};