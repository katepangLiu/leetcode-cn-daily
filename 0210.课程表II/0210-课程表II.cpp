class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // BFS
        // ����ȱ��ڽӾ���
        // ���Ϊ0�Ľڵ���� queue
        // ���� queue, 
        //      ɾ����ǰ�ڵ㣬�ڽӽڵ����-1�����Ϊ0�Ľڵ����queu

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