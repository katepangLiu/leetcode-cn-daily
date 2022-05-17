class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //prerequisites 为空，表示课程间不存在前后关系;
        if( prerequisites.size() == 0) {
            return true;
        }

        int m = prerequisites.size();
        int n = prerequisites[0].size();
        vector<int> flags(numCourses); //0-初识状态；1-在本次路径被访问过；-1-在其他路径被访问过;
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
        //在别的深度路径中出现过
        if( flags[i] == -1 ) { 
            return true;
        }
        //在一次深度路径中再次出现，有环;
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