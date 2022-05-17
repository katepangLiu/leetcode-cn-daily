class Solution {
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        //求邻接表;
        //遍历顶点
        //  相邻点的颜色标记为不可用;
        //  从可用的颜色中选择一个标记当前节点;

        vector<int>answer(N);
        vector<vector<int>> G(N);
        for( auto& edge : paths ) {
            G[edge[0]-1].push_back(edge[1]-1);
            G[edge[1]-1].push_back(edge[0]-1);
        }

        for( int cur =0; cur <N; cur++ ) {
            set<int> color = {1, 2, 3, 4};
            for( int adj : G[cur] ) {
                color.erase( answer[adj]);
            }
            answer[cur] = *color.begin();
        }

        return answer;
    }
};