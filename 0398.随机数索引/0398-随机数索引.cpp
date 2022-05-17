class Solution {
public:
    Solution(vector<int>& nums) {
        pvec = &nums;
    }
    
    int pick(int target) {
        int count = 0;
        int res = 0;
        for (int i=0;i<(*pvec).size();++i){
            if ((*pvec)[i] == target){
                ++count;
                if (rand() % count == (count-1) )
                    res = i;
            }
        }
        return res;
    }
private:
    vector<int>* pvec;
};
/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */