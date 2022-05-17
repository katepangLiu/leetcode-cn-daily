class Solution {
public:
    int longestMountain(vector<int>& A) {
        int n = A.size();
        vector<int> tops;
        int ans = 0;

        for( int i=1; i<n-1; i++ ) {
            if( A[i] > A[i-1] && A[i] > A[i+1] ) {
                tops.push_back(i);
                ans = 3;
            }
        }

        for( int top : tops ) {
            int l = top-2;
            int r = top+2;
            int len = 3;

            while( l>=0 && A[l]< A[l+1] ) {
                len++;
                l--;
            }
            while( r<n && A[r] < A[r-1] ) {
                len++;
                r++;
            }

            cout << A[top] <<',' << l << ',' << r ;
            ans =max( ans, len);
        }
        
        return ans;
    }
};