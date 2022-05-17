class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        //A相信B, 则A->B
        //法官是一个特殊的节点: 出度=0,入度=N-1;
        //vector<vector<int>> G(N);
        vector<int> inDegree(N);
        vector<int> outDegree(N);
        for( vector<int>& edge : trust ) {
            inDegree[edge[1]-1]++;
            outDegree[edge[0]-1]++;
            //G[edge[1]].push_back(edge[0]);
        }

        for( int i=0; i<N; i++ ) {
            if( inDegree[i] == N-1 && outDegree[i] == 0 ) {
                return i+1;
            }
        }

        return -1;
    }
};