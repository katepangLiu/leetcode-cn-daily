class Solution {
public:
    string multiply(string num1, string num2) {
        int m = num1.length();
        int n = num2.length();
        string ans;
        vector<string> buff;
        if( num1 == "0" || num2 == "0" ) {
            return "0";
        }

        for( int i=m-1; i>=0; i-- ) {
            int val = 0;
            int val1 = i>=0 ? (num1[i]-'0') : 0;
            string res;

            for( int j=i+1; j<m; j++ ) {
                res.push_back('0');
            }

            int j = n-1;
            while( j>=0 || val ) {
                int val2 = j>=0 ? (num2[j]-'0') : 0;
                j--;
                val += val1*val2;
                res.push_back( val%10 + '0');
                val = val/10;
            }
            buff.push_back(res);
            cout << res << endl;
        }

        int nBuff = buff.size();
        int val = 0;
        for( int i=0; i< buff[nBuff-1].size() ; i++ ) {
            vector<int> valBuff(nBuff);
            for( int j=0; j< nBuff; j++ ) {
                valBuff[j] = i<buff[j].size() ? buff[j][i] - '0' : 0;
                val += valBuff[j];
            }
            ans.push_back(val%10 + '0');
            val = val/10;
        }
        while( val > 0 ) {
            ans.push_back( val%10 + '0' );
            val = val/10;
        }

        //去掉无效的0;
        int i=ans.length()-1;
        for( ; i>=0; i-- ) {
            if( ans[i] != '0' ) {
                break;
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};