class Solution {
public:
    vector<vector<int>> ans;
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        int n = nums.size();
        set<int> memo; 
        for( int i=0; i<n; i++ ) {
            if( memo.count( nums[i] ) ) {
                continue;
            }
            
            dfs( nums, n, {}, INT_MIN, i);
            memo.emplace( nums[i] );
        }

        return ans;
    }

    void dfs( vector<int>& nums, int n, vector<int> tmp, int prev, int i ) {
        if( nums[i] < prev ) {
            return;
        }

        tmp.push_back(nums[i]);

        if( tmp.size() > 1 ) {
            ans.push_back(tmp);
        }

        set<int> memo; 
        for( int j=i+1; j<n; j++ ) {
            if( memo.count( nums[j] ) ) {
                continue;
            }
            
            dfs(nums, n, tmp, nums[i], j);
            memo.emplace( nums[j] );
        }
    }
};