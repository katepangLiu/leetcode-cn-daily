class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int num = 0;
        vector<int> ans;
        map<int, int> cache;

        for(int i=0; i<nums.size(); i++){
            num = target-nums[i];

            auto it = cache.find(num);
            if( it != cache.end() ){
                ans.push_back(it->second);
                ans.push_back(i);
            }else{
                cache.insert( {nums[i],i} );
            }
        }

        return ans;
    }
};