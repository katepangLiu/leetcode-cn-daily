class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        //理想情况下，均等划分成m个连续子数组，各自和的最大值最小;
        int n = nums.size();
        long sum = 0;
        int maxNum = 0;
        for( int& num : nums ) {
            maxNum = max( maxNum, num);
            sum += num;
        }

        long left = sum/m;
        long right = sum;
        int ans = 0;

        cout << left << ',' << right << endl;

        while( left <= right ) {
            long mid = left + (right-left)/2;
            if( check(nums, m, mid) ) {
                ans = mid;
                right = mid-1;
            } else {
                left = mid+1;
            }
        }

        return ans;
    }

    bool check(vector<int>& nums, int m, long maxSubSum) {
        cout << maxSubSum << endl;
        int n = nums.size();
        int subCount = 0;
        int i = 0;

        while( i<n ) {
            int j = i;
            long subSum = 0;
            for( ; j<n; j++ ) {
                subSum += nums[j];
                if( subSum > maxSubSum ) {
                    break;
                }
            }

            cout << i << '|' << j << ':' << subSum << endl;

            subCount++;
            i = j;

            if( subCount == m && i != n ) {
                return false;
            }    
            
        }

        return true;
    }
};