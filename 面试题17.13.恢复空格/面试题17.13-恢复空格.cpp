class Solution {
public:
    int respace(vector<string>& dictionary, string sentence) {
        int n = sentence.size();
        vector<int> dp(n+1);
        unordered_set<string_view> wordDict;
        for( const string& word : dictionary ) {
            wordDict.insert(word);
        }
        string_view sv(sentence);
        dp[0] = 0;

        for( int i=1; i<n+1; i++ ) {
            dp[i] = dp[i-1] + 1;
            for( int j=0; j<i; j++ ) {
                if( wordDict.find( sv.substr(j, i-j)) != wordDict.end() ) {
                    dp[i] = min( dp[i], dp[j] );
                }
            }
        }

        return dp[n];
    }
};