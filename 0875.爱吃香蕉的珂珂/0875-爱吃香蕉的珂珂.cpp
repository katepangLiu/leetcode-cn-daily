class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        int n = piles.size();
        long long sum = 0;
        int maxPile = 0;
        for( int& pile : piles ) {
            maxPile = max( maxPile, pile);
            sum += pile;
        }

        int left = sum/H;
        if( sum%H ) {
            left++;
        }
        int right = maxPile;
        int ans = left;

        cout << left << ',' << right << endl;

        while( left <= right ) {
            int mid = left + (right-left)/2;
            if( check(piles, H, mid) ) {
                ans = mid;
                right = mid-1;
            } else {
                left = mid+1;
            }
        }
        return ans;
    }

    bool check(vector<int>& piles, int H, int rate) {
        int hour = 0;
        int n = piles.size();
        cout << rate << endl;

        for( int i=0; i<n; i++ ) {
            int pile = piles[i];
            hour += pile/rate;
            if( pile%rate ) {
                hour++;
            }
            if( hour > H ) {
                return false;
            }
        }

        return true;
    }
};