class Solution {
private:
    vector<vector<int>> ans;
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        deque<int> path;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        dfs(nums, n, path, 0);
        return ans;
    }

    void dfs( vector<int>& nums,  int n,  deque<int>& path, int beg ) {
        ans.emplace_back(path.begin(), path.end());
        if( beg == n ) {
            return;
        }

        set<int> memo;
        for( int i=beg; i<n; i++ ) {
            if( memo.count(nums[i]) ) {
                continue;
            }
            memo.insert(nums[i]);
            path.push_back(nums[i]);
            dfs( nums, n, path, i+1 );
            path.pop_back();
        }
    }
};