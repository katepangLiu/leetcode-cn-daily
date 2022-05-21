class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        set<int> counts;
        for( auto &num : nums ) {
            if( counts.count(num) ) {
                return num;
            }
            counts.insert(num);
        }
        // Never
        return -1;
    }
};