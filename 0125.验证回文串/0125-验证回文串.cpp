class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.length();
        int l = 0;
        int r = n-1;
        while( l < r ) {
            char head = s[l];
            char tail = s[r];
            if(!validChar(head)) {
                l++;
                continue;
            }
            if(!validChar(tail)) {
                r--;
                continue;
            }
            if( head != tail ) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }

    bool validChar(char& ch) {
        if( '0' <= ch && ch <= '9' ) {
            return true;
        }
        if( 'a' <= ch && ch <= 'z' ) {
            return true;
        }
        if( 'A' <= ch && ch <= 'Z' ) {
            ch -= 'A' - 'a';
            return true;
        }
        return false;
    }

};