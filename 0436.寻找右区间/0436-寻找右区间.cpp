class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> ans(n, -1);
        
        vector<pair<int,int>> starts(n);
        for( int i=0; i<n; i++ ) {
            starts[i] = pair<int,int>(intervals[i][0], i);
        }
        sort(starts.begin(), starts.end());

        for( int i=0; i<n; i++ ) {
            auto low = lower_bound( starts.begin(), starts.end(), pair<int,int>(intervals[i][1], 0) );
            if( low != starts.end() ) {
                ans[i] = low->second;
            }
        }
        return ans;
    }
};