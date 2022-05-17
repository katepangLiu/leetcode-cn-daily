class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // BFS
        // 求入度表，邻接矩阵
        // 入度为0的节点放入 queue
        // 遍历 queue, 
        //      删除当前节点，邻接节点入度-1，入度为0的节点放入queu

        vector<int> inDegrees(numCourses);
        vector<vector<int>> aujacents(numCourses);
        queue<int> zeroQueue;
        int num = numCourses;
        vector<int> courses;

        for( auto& edge : prerequisites ) {
            inDegrees[edge[0]]++;
            aujacents[edge[1]].push_back(edge[0]);
        }

        for( int i=0; i<numCourses; i++ ) {
            if( inDegrees[i] == 0 ) {
                zeroQueue.push(i);
            }
        }

        while( !zeroQueue.empty() ) {
            int cur = zeroQueue.front();
            zeroQueue.pop();
            courses.push_back(cur);
            num--;
            for( int& next : aujacents[cur] ) {
                inDegrees[next]--;
                if( inDegrees[next] == 0 ) {
                    zeroQueue.push(next);
                }
            }
        }

        if( num == 0 ) {
            return courses;
        }
        return {};
    }
};