class Solution {
public:
    vector<vector<int>> ans;
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        deque<int> path;
        backtrace(k, n, 1, path);
        return ans;
    }

    void backtrace(int k, int n, int begin, deque<int>& path) {
        if( path.size() == k ) {
            if( n == 0 ) {
                ans.emplace_back( path.begin(), path.end() );
            }
            return;
        }

        for( int i=begin; i<=9; i++ ) {
            n -= i;
            path.push_back(i);
            backtrace(k, n, i+1, path);
            path.pop_back();
            n += i;
        }
    }
};