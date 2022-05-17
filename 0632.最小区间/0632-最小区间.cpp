class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> freq; //< val, index of nums that include val>
        int vMax = INT_MIN;
        int vMin = INT_MAX;

        for(int i=0; i<n; i++) {
            for( int val : nums[i] ) {
                freq[val].push_back(i);
                vMax = max(vMax, val);
                vMin = min(vMin, val);
            }
        }

        vector<int> winFreq(n);
        int left = vMin;
        int right = vMin;
        int bestLeft = vMin;
        int bestRight = vMax;
        int nInclude = 0;

        while( right <= vMax ) {
            if( freq.count(right) == 0 ) {
                right++;
                continue;
            }

            for( int i : freq[right] ) {
                winFreq[i]++;
                if( winFreq[i] == 1 ) {
                    nInclude++;
                }
            }
            while( nInclude == n ) {
                if( right - left < bestRight - bestLeft) {
                    bestLeft = left;
                    bestRight = right;
                }

                if( freq.count(left) == 0 ) {
                    left++;
                    continue;
                }

                for( int i: freq[left] ) {
                    winFreq[i]--;
                    if( winFreq[i] == 0 ) {
                        nInclude--;
                    } 
                }
                left++;
            }
            right++;
        }
        return {bestLeft, bestRight};
    }
};