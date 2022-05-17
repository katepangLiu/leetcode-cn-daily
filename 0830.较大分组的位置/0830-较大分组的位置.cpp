class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> ans;
        char last = ' '; 
        int count = 0;
        int i=0; 
        for( ;i< s.length(); i++ ) {
            if( s[i] == last ) {
                count++;
            } else {
                if( count >=3 ) {
                    ans.push_back( {i-count, i-1} );
                }
                count = 1;
            }
            last = s[i];
        }
        if( count>=3 ) {
            ans.push_back( {i-count, i-1} );
        }

        return ans;
    }
};