class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.length();
        for( int len=1; len<= n/2; len++) {
            if( n%len == 0 ) {
                int i=0;
                int j=i+len;
                bool isMatch = true;

                while( j < n ) {
                    if( s[i] != s[j] ) {
                        isMatch = false;
                        break;
                    }
                    j++;
                    i = (i<len-1) ? i+1 : 0 ;
                }
                
                if( isMatch ) {
                    return true;
                }
            }
        }

        return false;
    }
};