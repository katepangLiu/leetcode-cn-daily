class Solution {
public:
    bool canJump(vector<int>& nums) {
        int next = 0;
        for( int cur=0; cur<nums.size(); cur++ ) {
            if( cur > next ) {
                return false;
            }

            next = max(next, cur + nums[cur]);
        }

        return true;
    }
};