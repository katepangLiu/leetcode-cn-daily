class Solution {
public:
    int minTime(vector<int>& time, int m) {
        int n = time.size();
        if( m == n ) {
            return 0;
        }

        int maxTime = INT_MIN;
        int sum = 0;
        for( auto t : time ) {
            maxTime = max(maxTime, t);
            sum += t;
        }
        if ( m == 1 ) {
            return sum - maxTime;
        }

        int left = 0;
        int right = sum - maxTime;
        
        int ans = 0;
        while( left <= right ) {
            int mid = left+(right-left)/2;
            if( check(time, m, mid) ) {
                ans = mid;
                right = mid-1;
            } else {
                left = mid+1;
            }
        }

        return ans;
    }

    bool check(vector<int>& time, int m, int dayTimes) {
        //cout << "check:" << dayTimes << endl;
        int n = time.size();
        int days = 0;
        int i = 0;
        while ( i < n ) {
            //cout << "i:" << i << endl;
            int times = 0;
            int j = i;
            int dayMaxTime = 0;
            
            for( ; j<n; j++) {
                times += time[j];
                //cout <<"i:" << i << " j:" << j << " times:" << times << endl;
                dayMaxTime = max(dayMaxTime, time[j]);
                if( times - dayMaxTime > dayTimes ) {
                    break;
                }
            }
            i = j;
            days++;
            if( days > m ) {
                return false;
            }
        }

        return true;
    }
};