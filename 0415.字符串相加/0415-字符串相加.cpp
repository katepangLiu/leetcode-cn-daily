class Solution {
public:
    string addStrings(string num1, string num2) {
        int m = num1.size();
        int n = num2.size();
        if( m == 0) {
            return num2;
        }
        if( n == 0 ) {
            return num1;
        }

        int i=m-1;
        int j=n-1;
        int k = 0;
        string ans;
        int val = 0;
        int val1 = 0;
        int val2 = 0;

        while( i>=0 || j>=0 || val ) {
            val1 = i>=0 ? num1[i] - '0' : 0 ;
            val2 = j>=0 ? num2[j] - '0' : 0 ;
            val += val1 + val2;
            ans.push_back(val%10 + '0');
            val = val/10;
            i--;
            j--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};