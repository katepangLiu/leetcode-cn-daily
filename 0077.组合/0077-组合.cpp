class Solution {

public:
    vector<vector<int>> ans;
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> buf(k);
        backtrace(n, k, 0, 0, buf);
        return ans;
    }

    void backtrace(int n, int k, int i, int prev, vector<int>& buf) {
        if( i == k ) {
            ans.push_back( buf );
            return;
        }
 
        for(int j=prev+1; j<=n; j++ ) {
            buf[i] = j;
            backtrace(n, k, i+1, j, buf);
        }        
    }
};