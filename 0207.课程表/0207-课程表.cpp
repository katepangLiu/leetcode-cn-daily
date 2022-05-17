class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //prerequisites Ϊ�գ���ʾ�γ̼䲻����ǰ���ϵ;
        if( prerequisites.size() == 0) {
            return true;
        }

        int m = prerequisites.size();
        int n = prerequisites[0].size();
        vector<int> flags(numCourses); //0-��ʶ״̬��1-�ڱ���·�������ʹ���-1-������·�������ʹ�;
        vector<vector<int>> adjacents(numCourses);
        for( auto& edge : prerequisites ) {
            adjacents[edge[1]].push_back(edge[0]);
        }

        for( int i=0; i<numCourses; i++ ) {
            if( dfs(adjacents, flags, i) == false ) {
                return false;
            }
        }
        return true;
    }

    bool dfs( vector<vector<int>>& adjacents, vector<int>& flags, int i) {
        //�ڱ�����·���г��ֹ�
        if( flags[i] == -1 ) { 
            return true;
        }
        //��һ�����·�����ٴγ��֣��л�;
        if( flags[i] == 1 ) { 
            return false;
        }
        flags[i] = 1;

        for( int j : adjacents[i] ) {
            if( dfs(adjacents, flags, j) == false ) {
                return false;
            }
        }
        flags[i] = -1;
        return true;
    }
};