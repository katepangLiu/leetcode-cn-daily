class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        //ע����ɵ�2��ϸ�ڣ�
        //������
        //����������;

        int n = nums.size();
        if( n == 0 ) {
            return 0;
        }

        int minLen = n+1;
        int l = 0;
        int r = 0;
        int sum = 0;

        while( r < n ) {
            sum += nums[r];
            r++;

            while( sum >= s ) {
                minLen = min( minLen, r-l);
                sum -= nums[l];
                l++;
            }
        }

        if(minLen > n) {
            return 0;
        }
        return minLen;
    }
};