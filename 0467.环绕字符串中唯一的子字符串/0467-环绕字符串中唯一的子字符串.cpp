class Solution {
public:
    int findSubstringInWraproundString(string p) {
        vector<int> dp(26);
        int count = 0;
        for( int i=0; i<p.length(); i++ ) {
            if( i == 0 ) {
                count = 1;
            // �����ǰ�ַ���ǰһ�ַ�������������ѭ���ַ������Ӵ�
            } else if( 1 == ((p[i] - p[i-1] + 26) % 26) ) {
                count++;
            } else {
                count =1;
            }
            int j = p[i] - 'a'; 
            dp[j] = max(dp[j], count);
        }

        return accumulate(dp.begin(), dp.end(), 0);
    }
};