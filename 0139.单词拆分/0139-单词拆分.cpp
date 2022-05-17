class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
         unordered_set<string> wordDictSet;
        for( auto word : wordDict ) {
            wordDictSet.insert(word);
        } 

        int n = s.size();
        vector<bool> dp(n+1);
        dp[0] = true;
       
        for( int i =1; i<n+1; i++ ) {
            for( int j=0; j<i; j++ ) {
                if( dp[j] && wordDictSet.find(s.substr(j, i-j)) != wordDictSet.end() ) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
};