class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size();
        int n = needle.size();
        
        if( n == 0 ) {
            return 0;
        }
        if( m == 0 ) {
            return -1;
        }

        for( int i=0; i<m; i++ ) {
            int j = 0;
            int count = 0;
            if( m -i < n ) {
                break;
            }
            while( (i+j<m) && j <n && haystack[i+j] == needle[j] ) {
                count++;
                if( count == n )  {
                return i;
                }
                j++;
            }
            
        }

        return -1;
    }
};