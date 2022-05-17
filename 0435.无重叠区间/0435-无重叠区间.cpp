class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort( intervals.begin(), intervals.end(), compare);
        int prev = INT_MIN;
        int count = 0;
        for( auto& interval : intervals ) {
            cout << prev << ',' << interval[0] << ',' << interval[1] << endl;
            if( interval[0] < prev ) {
                count++;
                continue;
            }
            prev = interval[1];
        }

        return count;
    }

    static bool compare(vector<int>& a, vector<int>& b) {
        if( a[1] < b[1] ) {
            return true;
        }
        return false;
    }
};