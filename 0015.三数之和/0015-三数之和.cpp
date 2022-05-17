class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        if( n<3 ) {
            return ans;
        }

        sort(nums.begin(), nums.end());
        
        for( int i=0; i<n; i++ ) {
            if( nums[i] >0 ) {
                break;
            }
            if( i>0 && nums[i] == nums[i-1] ) {
                continue;
            }

            int l=i+1;
            int r=n-1;
            int target = 0-nums[i];
            while( l<r ) {
                int sum = nums[l] + nums[r];
                if( sum == target ) {
                    ans.push_back( {nums[i], nums[l], nums[r]} );
                    int prevLeft = nums[l];
                    int prevRight = nums[r];
                    while( l<r && prevLeft == nums[l] ) {
                        l++;
                    }
                    while( l<r && prevRight == nums[r] ) {
                        r--;
                    }
                } else if( sum <target ) {
                    l++;
                } else {
                    r--;
                }
            }
        }

        return ans;
    }
};