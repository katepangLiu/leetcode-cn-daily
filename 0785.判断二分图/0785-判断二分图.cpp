const int UNCOLORED = 0;
const int RED = 1;
const int GREEN = 2;

class Solution {
private:
    bool vaild;

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vaild = true;
        vector<int> colors(n, UNCOLORED);
        for( int i=0; i<n && vaild; i++ ) {
            if( colors[i] == UNCOLORED ) { // 只对未染色的节点操作;
                dfs(graph, colors, i, RED);
            }
        }

        return vaild;
    }

    void dfs(const vector<vector<int>>& graph, vector<int>& colors, int index, int c) {
        colors[index] = c;
        int neighborColor = ( c == RED ? GREEN:RED ) ;

        for( int neighbor : graph[index] ) {
            if( colors[neighbor] == UNCOLORED ) {
                dfs(graph, colors, neighbor, neighborColor);
            } else if( colors[neighbor] != neighborColor ) {
                vaild = false ;
                return;
            }
        } 

    }

};