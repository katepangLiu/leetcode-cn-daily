class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> dict;
        for( int i=0; i< order.size(); i++ ) {
            dict[order[i]] = i;
        }

        int maxLen = 0;
        for( int i=0; i< words.size(); i++ ) {
            maxLen = max(maxLen, (int)words[i].length());
        }

        for( int i=1 ;i<words.size(); i++ ) {
            for( int j=0; j<words[i-1].length(); j++ ) {
                int a = dict[words[i-1][j]];
                int b = j<words[i].length()?dict[words[i][j]]:-1;
                if( a < b ) {
                    break;
                }
                if( a > b ) {
                    return false;
                }
            }
        }

        return true;
    }
};