class Solution {
public:
    vector<vector<int>> ans;
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        //��֤�����������򣬱����ظ�;
        sort( candidates.begin(), candidates.end() );
        deque<int> buf;
        backtrace(candidates, target, buf, candidates[0]);
        return ans;
    }

    void backtrace( vector<int>& candidates, int target, deque<int>& buf, int cur) {    
        if( target == 0 ) {
            ans.emplace_back( buf.begin(), buf.end() ) ;
            return;
        }

        for( int& num : candidates ) {
            //cout << num << endl;
            //��֤�����������򣬱����ظ�;
            if( num < cur ) {
                continue;
            }

            target -= num;
            if( target < 0 ) {
                return;
            }
            buf.push_back(num);
            backtrace( candidates, target, buf, num);
            buf.pop_back();
            target += num;
        }
    }
};