class Solution {
public:
    vector<int> mostVisited(int n, vector<int>& rounds) {
        vector<int> visitCount(n);
        int m = rounds.size();
        
        int start = rounds[0];
        int end = rounds[m-1];
        vector<int> ans;
        if( start <= end ) {
            for( int i=start; i<=end; i++ ) {
            ans.push_back(i);
            }
        } else {
            for( int i=start; i<=n; i++ ) {
                ans.push_back(i);
            }
            for( int i=1; i<=end; i++ ) {
                ans.push_back(i);
            }
            sort( ans.begin(), ans.end() );
        }
        
        return ans;
    }
};