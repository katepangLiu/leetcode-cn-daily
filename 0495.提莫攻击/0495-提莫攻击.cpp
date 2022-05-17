class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int total = 0;
        int n = timeSeries.size();
        if( n == 0 ) {
            return total;
        } 
        total += duration;
        for( int i=1; i<n; i++ ) {
            total += (timeSeries[i]-timeSeries[i-1] >= duration) ? duration : timeSeries[i]-timeSeries[i-1] ;
        }

        return total;
    }
};