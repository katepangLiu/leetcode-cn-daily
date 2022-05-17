class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int ans = 0;
        int n = points.size();
        vector<int> minDists(n, INT_MAX);
        vector<bool> vis(n);
        minDists[0] = 0;

        //循环每一次加入一个节点;
        for( int cnt=0; cnt<n; cnt++ ) {
            int minDist = INT_MAX;
            int u = 0; //下一个要新加入的节点;

            //从备选集合中挑选出与 集合 距离最小的节点 作为下一个新加入的节点;
            for( int i=0; i<n; i++ ) {
                if( !vis[i] && minDists[i] < minDist ) {
                    minDist = minDists[i];
                    u = i;
                }
            }

            ans += minDist;
            vis[u] = true;
            
            //更新备选集中每个节点与集合的最短距离;
            for( int i=0; i<n; i++ ) {
                if( !vis[i] ) {
                    int newDist = abs(points[i][0]-points[u][0]) + abs(points[i][1]-points[u][1] );
                    minDists[i] = min( minDists[i], newDist );
                }
            }
        }

        return ans;
    }
};