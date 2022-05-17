class Solution {
public:
    bool isAnagram(string s, string t) {
        if( s.size() != t.size() ) {
            return false;
        }

        map<char, int> dict;
        for( char ch : s  ) {
            ++dict[ch];
        }

        for( char ch : t ) {
            --dict[ch];
        }

        for( auto pair : dict ) {
            if( pair.second != 0 ) {
                return false;
            }
        }

        return true;
    }
};