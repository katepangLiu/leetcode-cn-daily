class Solution {
public:
    bool canPermutePalindrome(string s) {
        map<char, int> dict;
        for( auto c : s ) {
            ++dict[c];
        }

        int count = 0;
        for( auto pair : dict ) {
            if( pair.second%2 ) {
                count++;
            }
            if( count > 1 ) {
                return false;
            }
        }

        return true;
    }
};