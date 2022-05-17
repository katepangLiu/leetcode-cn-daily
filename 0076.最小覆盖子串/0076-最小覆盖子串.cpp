class Solution {
public:
    string minWindow(string s, string t) {
        int sLen = s.length();
        int tLen = t.length();
        if( sLen == 0 || tLen == 0 ) {
            return "";
        }

        map<char, int> tFreq;
        map<char, int> winFreq;
        for( char c : t ) {
            tFreq[c]++;
        }

        int distance = 0;
        int begin = 0;
        int minLen = sLen+1;
        //滑动窗口为 [left, right), 初识为 [0,0) 空窗口
        int left = 0;
        int right = 0; 

        while( right < sLen ) {
            char rc = s[right]; 
            
            //不属于t的字符
            if( tFreq[rc] == 0) {
                right++;
                continue;
            }

            //属于t的字符
            //相应字符在窗口中的频数未超过在t中的频数;
            if( winFreq[rc] < tFreq[rc]) {
                distance++;
            }
            winFreq[rc]++;
            right++;

            //窗口中包含所有t中的字符;
            while( distance == tLen ) {
                int len = right - left;
                if( len < minLen ) {
                    minLen = len;
                    begin = left;
                }

                char lc = s[left];
                if( tFreq[lc] == 0 ) {
                    left++;
                    continue;
                }

                if( winFreq[lc] == tFreq[lc] ) {
                    distance--;
                }
                winFreq[lc]--;
                left++;
            }
        }

        if( minLen > sLen ) {
            return "";
        }
        return s.substr(begin, minLen);
    }
};