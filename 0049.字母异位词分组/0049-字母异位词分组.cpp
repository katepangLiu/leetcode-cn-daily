class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, int> memo;
        vector<vector<string>> ans;

        for( string& str : strs ) {
            string tmp = str;
            sort( tmp.begin(), tmp.end() );
            if( memo.find(tmp) != memo.end() ) {
                ans[memo[tmp]].push_back(str);
            } else {
                ans.push_back({str});
                memo[tmp] = ans.size()-1;
            }
        }

        return ans;
    }
};