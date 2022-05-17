class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int sLen = s.length();
        int pLen = p.length();

        if( sLen < pLen) {
            return {};
        }

        vector<int> ans;
        int l = 0;
        int r = 0;
        map<char, int> winFreq;
        map<char, int> pFreq;
        int distance = 0;
        for( char c : p ) {
            pFreq[c]++;
        }

        while( r < sLen ) {
            if( winFreq[s[r]] < pFreq[s[r]] ) {
                distance++;
            }
            winFreq[s[r]]++;
            r++;

            if( r - l == pLen) {
                if( distance == pLen ) {
                    ans.push_back(l);
                }
                if( winFreq[s[l]] <= pFreq[s[l]] ){
                    distance--;
                }
                winFreq[s[l]]--;
                l++;
            }
        }

        return ans;
    }
};