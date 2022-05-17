class Solution {
public:
    string thousandSeparator(int n) {
        string ans;
        int flag = 0;
        
        if( n == 0 ) {
            return "0";
        }
        
        while( n ) {
            if( flag == 3 ) {
                ans.push_back('.');
                flag = 0;
            }
            ans.push_back( n%10 + '0' );
            n = n/10;
            flag++;
        }
        
        reverse( ans.begin(), ans.end() );
        return ans;
    }
};