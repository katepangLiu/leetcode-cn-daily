class Solution {    
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n);
        dfs( rooms, visited, 0);
        for( int i=0; i<n; i++ ) {
            if( !visited[i] ) {
                return false;
            }
        }
        return true;
    }

    void dfs(vector<vector<int>>& rooms, vector<bool>& visited, int index) {
        visited[index] = true;
        for( auto next : rooms[index] ) {
            if( visited[next] ) {
                continue;
            }
            dfs(rooms, visited, next);
        }
    }
};