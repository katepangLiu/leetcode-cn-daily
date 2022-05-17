class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int begin = 0;
        int maxLen = 0;
        int len = 0;
        if( n < 2 ) {
            return s;
        }

        vector<vector<int>> dp( n, vector<int>(n));

        for( int diff = 0; diff < n; diff++ ) {
            for( int i =0; i< n-diff; i++ ) {
                int j = i+diff;
                if( diff == 0 ) {
                    dp[i][j] = 1;
                } else if( (diff == 1) || (diff ==2) ) { //��ֵΪ1��2ʱ������Ҫ�����ִ����������ʱ�Ӵ�����Ϊ0��1,��Ӱ����;
                    dp[i][j] = (s[i] == s[j]) ;
                } else {
                    dp[i][j] = (s[i] == s[j]) && dp[i+1][j-1];
                }
                
                len = diff+1;//�±��ֵ+1 = �ִ��ĳ���;
                if( dp[i][j] && (len > maxLen)  ) {
                    begin = i;
                    maxLen = len;
                }
            }
        }

        return s.substr(begin, maxLen);
    }
};