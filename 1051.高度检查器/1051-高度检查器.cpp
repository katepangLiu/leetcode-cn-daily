class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int ans = 0;
        vector<int> tmp(heights.begin(), heights.end());
        sort(tmp.begin(), tmp.end());

        for( int i=0; i<heights.size(); i++ ) {
            if( tmp[i] != heights[i] ) {
                ans++;
            }
        }

        return ans;
    }
};