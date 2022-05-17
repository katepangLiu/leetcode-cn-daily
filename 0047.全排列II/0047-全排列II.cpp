class Solution {
public:
    vector<vector<int>> ans;
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        deque<int> path;
        int n  = nums.size();
        vector<bool> vis(n);
        backtrace( nums, vis, n, path, 0);
        return ans;
    }

    void backtrace(vector<int>& nums, vector<bool> vis, int n, deque<int>& path, int index) {
        //cout << i << nums[i] << endl;
        if( index == n ) {
            ans.emplace_back( path.begin(), path.end() );
            return;
        }

        set<int> memo;
        for( int i=0; i<n; i++ ) {
            if( vis[i] ) {
                continue;
            }
            if( memo.count(nums[i]) ) {
                continue;
            }
            vis[i] = true;
            memo.insert(nums[i]);
            path.push_back(nums[i]);
            backtrace(nums, vis, n, path, index+1);
            path.pop_back();
            vis[i] = false;
        }
    }
};