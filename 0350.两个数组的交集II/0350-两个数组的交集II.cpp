class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;

        map<int, int> dict;
        for( auto num : nums1 ) {
            dict[num]++;
        }        

        for( auto num : nums2 ) {
            if( dict.find(num) != dict.end() && dict[num] > 0 ) {
                dict[num]--;
                res.push_back(num);
            }
        }

        return res;
    }
};