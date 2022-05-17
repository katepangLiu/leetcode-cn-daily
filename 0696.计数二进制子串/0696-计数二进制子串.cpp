class Solution {
public:
    int countBinarySubstrings(string s) {
        vector<int> counts;
        int n = s.length();
        int i = 0;
        while( i<n ) {
            char c = s[i];
            int count = 0;
            while( i<n && s[i] == c ) {
                count++;
                i++;
            }
            counts.push_back(count);
        }

        int ans = 0;
        for( int i=1; i< counts.size(); i++ ) {
            ans += min( counts[i], counts[i-1] );
        }

        return ans;
    }
};