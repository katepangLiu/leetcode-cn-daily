class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int n = weights.size();
        int maxWeight = 0;
        long sum = 0;

        for( int& weight : weights ) {
            maxWeight = max(maxWeight, weight);
            sum += weight;
        }

        long left = maxWeight;
        long right = sum;
        int ans = left;

        while( left <= right ) {
            long mid = left + (right-left)/2;
            if( check(weights, D, mid) ) {
                ans = mid;
                right = mid-1;
            } else {
                left = mid +1;
            }
        }
        
        return ans;
    }

    bool check( vector<int>& weights, int D, int dayWeight) {
        int day = 0;
        int n = weights.size();
        int i = 0;
        
        while ( i < n ) {
            int j = i;
            int weight = 0;
            for( ; j<n; j++ ) {
                weight += weights[j];
                if( weight > dayWeight) {
                    break;
                }
            }

            day++;
            i = j;

            if( day > D ) {
                return false;
            }
        }

        return true;
    }
};