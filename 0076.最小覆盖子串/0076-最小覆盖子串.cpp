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
        //��������Ϊ [left, right), ��ʶΪ [0,0) �մ���
        int left = 0;
        int right = 0; 

        while( right < sLen ) {
            char rc = s[right]; 
            
            //������t���ַ�
            if( tFreq[rc] == 0) {
                right++;
                continue;
            }

            //����t���ַ�
            //��Ӧ�ַ��ڴ����е�Ƶ��δ������t�е�Ƶ��;
            if( winFreq[rc] < tFreq[rc]) {
                distance++;
            }
            winFreq[rc]++;
            right++;

            //�����а�������t�е��ַ�;
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