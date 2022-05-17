class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int m = strs.size();
        int n = strs[0].size();
        int count = 0;

        for( int i=0; i<n; i++ ) {
            int j=0;
            int flag = 0;
            char last = strs[j][i];
            for( j=1; j<m; j++ ) {
                if( last > strs[j][i] ) {
                    count++;
                    break;
                }
                last = strs[j][i];
            }
        }

        return count;
    }
};