class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n-k+1);
        deque<int> dq;
        
        int len = 0;
        int j = 0;

        for( int i=0; i<n; i++ ) {
            //cout << nums[i-k] << ' ' << nums[i] << endl;
            len++;
            while( !dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            dq.push_back( i );
            //cout << len << endl;

            if( len == k) {
                if( (i-k) == dq.front() ) {
                    dq.pop_front();
                }
                //cout << dq.front() << endl;
                ans[j++] = nums[dq.front()];
                len--;
            }
        }

        return ans;
    }
};