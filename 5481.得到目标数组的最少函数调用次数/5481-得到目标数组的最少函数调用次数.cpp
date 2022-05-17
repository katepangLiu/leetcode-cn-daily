class Solution {
public:
    int minOperations(vector<int>& nums) {
        int multis=0; 
        int adds=0;
        for(auto num : nums)
        {
            int add = 0;
            int multi = 0;
            while(num) {
                if( num == 1 ) {
                    adds++;
                    break;
                }
                if( num%2 ) {
                    adds++;
                    num -=1;
                } else {
                    num /= 2;
                    multi++;
                }
            }
            
            multis = max(multis, multi);
            adds += add;
        }
        return multis + adds;
    }
};