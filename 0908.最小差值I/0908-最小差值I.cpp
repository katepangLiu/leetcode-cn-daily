class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int maxv = INT_MIN;
        int minv = INT_MAX;

        for( auto v : nums ) {
            maxv = max(maxv, v);
            minv = min(minv, v);
        }

        int diff = maxv - minv;
        if( diff <= 2*k ) {
            return 0;
        }

        return diff - 2*k;
    }
};