class Solution {
public:
    vector<vector<int>> ans;
public:    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        deque<int> path;
        sort( candidates.begin(), candidates.end());
        backtrace( candidates, target, path, 0);
        return ans;
    }

    void backtrace(vector<int>& candidates, int target, deque<int>& path, int begin) {
        cout << target << ',' << begin << endl;
        if( 0 == target ) {            
            ans.emplace_back( path.begin(), path.end() );
            return;
        }

        set<int> memo;

        for( int i= begin; i< candidates.size(); i++ ) {
            if( memo.count(candidates[i] ) > 0 ) {
                continue;
            }

            memo.insert( candidates[i] );
            target -= candidates[i];
            if( target < 0 ) {
                return;
            }

            path.push_back(candidates[i]);
            backtrace(candidates, target, path, i+1);
            path.pop_back();
            target += candidates[i];
        }
    }
};