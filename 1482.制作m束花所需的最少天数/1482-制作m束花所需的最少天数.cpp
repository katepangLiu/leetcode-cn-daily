class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int ans = -1;
        int n = bloomDay.size();
        //sort( bloomDay.begin(), bloomDay.end() );
        int left = INT_MAX;
        int right = INT_MIN;
        for( auto day : bloomDay ) {
            left = min( left, day);
            right = max(right, day);
        }

        while( left <= right ) {
            int mid = left + (right-left)/2;
            if( check(bloomDay, m, k, mid) ) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid +1;
            }
        }
        return ans;
    }

    bool check( vector<int>& bloomDay, int m, int k, int day ) {
        int n = bloomDay.size();
        int brunchCount = 0;
        int i = 0;

        while( i < n-k+1 ) {
            int flowerCount = 0;
            int j=i;
            for( ; j<i+k; j++ ) {
                if( bloomDay[j] > day ) {
                    i = j+1;
                    break;
                }
                flowerCount++;
            }

            if( flowerCount == k ) {
                brunchCount ++;
                i = j;
            }
            
            if( brunchCount >= m ) {
                return true;
            }
        }

        return false;
    }
};