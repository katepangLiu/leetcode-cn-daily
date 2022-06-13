class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int n = matchsticks.size();
        int count = accumulate( matchsticks.begin(), matchsticks.end(), 0);
        if ( count%4 != 0) {
            return false;
        }

        int len = count/4;
        vector<int> edges(4);
        sort( matchsticks.begin(), matchsticks.end(), greater<int>());

        return backtrace(matchsticks, n, edges, len, 0);
    }

    bool backtrace(vector<int>& matchsticks, int n, vector<int>& edges, int len, int i) {
        
        if( i == n ) {
            return true;
        }

        for( int e=0; e<4; e++ ) {
            edges[e] += matchsticks[i];
            if( edges[e] <= len && backtrace( matchsticks, n, edges, len, i+1)) {
                return true;
            }
            edges[e] -= matchsticks[i];
        }

        return false;
    }
};