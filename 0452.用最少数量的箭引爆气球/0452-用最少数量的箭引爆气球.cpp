class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if( points.size() == 1 ) {
            return 1;
        }

        sort( points.begin(), points.end(), compare );
        int count = 0;
        int prev = INT_MIN;

        for( auto& point : points ) {
            if( point[0] <= prev ) {
                count++;
            } else {
                prev = point[1];
            }
        }

        return points.size() - count;
    }

    static bool compare(vector<int>& a, vector<int>& b) {
        if( a[1] < b[1] ) {
            return true;
        }
        return false;
    }
};