class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        sort( position.begin(), position.end() );
        int right = (position[n-1] - position[0])/(m-1);
        int left = 1;
        int ans = 1;
        cout << right << ' ' << left << endl;

        while( left <= right ) {
            int mid = left + (right-left)/2;
            if( check( position, mid, m) ) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return ans;
    }

    bool check(vector<int>& position, int distance, int m) {
        int n = position.size();
        int prev = 0;
        int count = 1;
        for( int i =1; i<n; i++ ) {
            if( position[i] - position[prev] >= distance ) {
                count++;
                prev = i;
            }
            if( count == m ) {
                return true;
            }
        }
        return false;
    }
};