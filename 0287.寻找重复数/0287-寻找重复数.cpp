class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        //�ظ������ض��� [1,n-1]֮��
        int l = 1;
        int r = n-1;
        int ans = 0;

        while( l<=r ) {
            int mid = (l+r)/2;
            int count = 0;
            for( int num: nums ) {
                if( num <= mid ) {
                    count++;
                }
            }
            
            if( count <= mid ) {
                l = mid+1;
            } else {
                r = mid-1;
                ans = mid;
            }
        }

        return ans;
    }
};