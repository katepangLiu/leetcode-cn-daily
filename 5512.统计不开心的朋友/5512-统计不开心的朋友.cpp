class Solution {
public:
    int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) {
        vector<vector<int>> preferDict( n, vector<int>(n) );
        for( int i=0; i<n; i++ ) {
            int idx = 0;
            for( int j=0; j<n-1; j++ ) {
                preferDict[i][ preferences[i][j] ] = idx;
                idx++;
            }
        }

        set<int> memo;
        for( int i=0; i<pairs.size(); i++ ) {
            for( int j=0; j<pairs.size(); j++ ) {
                if( i == j ) {
                    continue;
                }

                auto& pairA = pairs[i];
                auto& pairB = pairs[j]; 

                if( unHappy(preferDict, pairA[0], pairA[1], pairB[0], pairB[1] ) ) {
                    memo.insert(pairA[0]);
                }
                if( unHappy(preferDict, pairA[1], pairA[0], pairB[0], pairB[1] ) ) {
                    memo.insert(pairA[1]);
                }
                if( unHappy(preferDict, pairA[0], pairA[1], pairB[1], pairB[0] ) ) {
                    memo.insert(pairA[0]);
                }
                if( unHappy(preferDict, pairA[1], pairA[0], pairB[1], pairB[0] ) ) {
                    memo.insert(pairA[1]);
                }           

            }

        }

        return memo.size();
    }

    bool unHappy(vector<vector<int>>& preferDict, int x, int y, int u, int v ) {
        if( preferDict[x][y] > preferDict[x][u] && preferDict[u][v] > preferDict[u][x] ) {
            return true;
        }

        return false;
    }
};