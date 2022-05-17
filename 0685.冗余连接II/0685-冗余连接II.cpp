class UnionFind {
private:
    vector<int> ancestors;
public:
    UnionFind(int n) : ancestors(n) {
        for( int i=0; i<n; i++ ) {
            ancestors[i] = i;
        }
    };

    int find(int i) {
        while( ancestors[i] != i ) {
            i = ancestors[i];
        }

        return i;
    }

    void unint(int u, int v) {
        ancestors[find(v)] = find(u);
    }

};

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        UnionFind uf(n+1);
        vector<int> parents(n+1);
        // 节点是 [1..N]
        for( int i=1; i<=n; i++ ) {
            parents[i] = i;
        }

        int conflict = -1;//产生冲突的边: 这个边[u,v] 使得 v有2个parent;
        int cycle = -1;//产生环的边; 这个边 [u, v] 使得 u,v 在并查集中属于同一个集;

        for( int i=0; i<n; i++ ) {
            int u = edges[i][0];
            int v = edges[i][1];

            if( parents[v] != v ) {
                conflict = i;
            } else {
                parents[v] = u;

                if( uf.find(u) == uf.find(v) ) {
                    cycle = i;
                } else {
                    uf.unint(u, v);
                }
            }
        }

        if( conflict < 0 ) {
            return edges[cycle];
        } 

        if( cycle >= 0 ) {
            int v = edges[conflict][1];
            return { parents[v], v}; 
        } else {
            return edges[conflict];
        }

    }
};