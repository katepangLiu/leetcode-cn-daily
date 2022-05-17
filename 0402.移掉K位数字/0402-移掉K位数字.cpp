class Solution {
public:
    string removeKdigits(string num, int k) {
        deque<char> dq;
        for( char c : num ) {
            while( !dq.empty() &&  c < dq.back() && k > 0 ) {
                dq.pop_back();
                k--;
            }
            dq.push_back(c);
        }

        while( k>0 ) {
            dq.pop_back();
            k--;
        }

        while( !dq.empty() && dq.front() == '0' ) {
            dq.pop_front();
        }
        if( dq.empty() ) {
            dq.push_back('0');
        }
        
        string ans( dq.begin(), dq.end() );
        return ans;
    }
};