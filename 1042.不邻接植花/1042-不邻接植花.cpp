class Solution {
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        //���ڽӱ�;
        //��������
        //  ���ڵ����ɫ���Ϊ������;
        //  �ӿ��õ���ɫ��ѡ��һ����ǵ�ǰ�ڵ�;

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