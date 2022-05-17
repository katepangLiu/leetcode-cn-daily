class UnionFind {
    vector<int> parents;

public:
    UnionFind(int n) : parents(n) {
        for( int i=0; i<n; i++ ) {
            parents[i] = i;
        }
    };

    void unite( int x, int y ) {
        int px = find(x);
        int py = find(y);
        if( px != py ) {
            parents[px] = py;
        }
    }

    int find( int x ) {
        while( x != parents[x] ) {
            x = parents[x];
        }
        return x;
    }
};

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        UnionFind uf (26);

        for( auto& equation : equations ) {
            if( equation[1] == '=' ) {
                int x = equation[0] - 'a';
                int y = equation[3] - 'a';
                cout << x << ',' << y << endl;
                uf.unite( x, y );
            }
        }

        for( auto& equation : equations ) {
            if( equation[1] == '!' ) {
                int x = equation[0] - 'a';
                int y = equation[3] - 'a';
                int px = uf.find(x);
                int py = uf.find(y);
                if( px == py ) {
                    return false;
                }
            }
        } 

        return true;
    }
};