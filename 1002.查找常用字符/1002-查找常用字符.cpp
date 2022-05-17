class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<string> res;
        int n = A.size();
        vector<unordered_map<char, int>> dict(n);
        for( int i=0; i<n; i++ ) {
            for( char ch : A[i] ) {
                dict[i][ch]++;
            }
        }

        for( auto pair : dict[0] ) {
            char ch = pair.first;
            int count = pair.second;
            for( int i=1; i<n; i++ ) {
                count = min( count, dict[i][ch]);
            }
            
            while( count ) {
                res.push_back( string(1, ch) );
                count--;
            }
        }

        return res;
    }
};