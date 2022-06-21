class Solution {
public:
    string defangIPaddr(string address) {
        vector<char> v1(address.begin(), address.end());
        vector<char> v2;

        for( auto x : v1 ) {
            if( x != '.' ) {
                v2.push_back(x);
            } else {
                v2.push_back('[');
                v2.push_back(x);
                v2.push_back(']');
            }
        }

        string ans(v2.begin(), v2.end());
        return ans;
    }
};