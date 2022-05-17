class Solution {
public:
    string replaceSpace(string s) {
        string ans;
        for( char& c : s ) {
            if( c == ' ' ) {
                ans += "%20";
            } else {
                ans += c;
            }
        }

        return ans;
    }
};