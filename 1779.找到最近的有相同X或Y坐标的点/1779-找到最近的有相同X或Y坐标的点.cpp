class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int minDst = INT_MAX;
        int ans = -1;
        for( int i=0; i<points.size(); i++ ) {
            int a = points[i][0];
            int b = points[i][1];
            int dst = INT_MAX;
            if (x == a) {
                dst = abs(b - y);
            } else if (y==b) {
                dst = abs(a-x);
            }
            if (dst < minDst) {
                minDst = dst;
                ans = i;
            }
        }

        return ans;
    }
};