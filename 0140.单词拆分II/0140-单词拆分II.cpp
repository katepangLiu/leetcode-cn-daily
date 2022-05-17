class Solution {
private:
    unordered_map<int, vector<string>> ans;
    unordered_set<string> wordSet;

public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        wordSet = unordered_set(wordDict.begin(), wordDict.end());
        backtrack(s, 0);
        return ans[0];
    }

    void backtrack(const string& s, int index) {
        if( ans.count(index) ) {
            return;
        }

        if( index == s.size() ) {
            ans[index] = {""};
            return;
        }

        ans[index] = {};
        for( int i=index+1; i<=s.size(); i++ ) {
            int wordLen = i-index;
            string word = s.substr(index, wordLen);

            if( wordSet.count(word) ) {
                backtrack(s, i);
                for( const string& ansWord : ans[i] ) {
                    ans[index].push_back( ansWord.empty() ? word : word + " " + ansWord);
                }
            }
        }
        
    }
};