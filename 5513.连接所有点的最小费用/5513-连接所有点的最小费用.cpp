class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int ans = 0;
        int n = points.size();
        vector<int> minDists(n, INT_MAX);
        vector<bool> vis(n);
        minDists[0] = 0;

        //ѭ��ÿһ�μ���һ���ڵ�;
        for( int cnt=0; cnt<n; cnt++ ) {
            int minDist = INT_MAX;
            int u = 0; //��һ��Ҫ�¼���Ľڵ�;

            //�ӱ�ѡ��������ѡ���� ���� ������С�Ľڵ� ��Ϊ��һ���¼���Ľڵ�;
            for( int i=0; i<n; i++ ) {
                if( !vis[i] && minDists[i] < minDist ) {
                    minDist = minDists[i];
                    u = i;
                }
            }

            ans += minDist;
            vis[u] = true;
            
            //���±�ѡ����ÿ���ڵ��뼯�ϵ���̾���;
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