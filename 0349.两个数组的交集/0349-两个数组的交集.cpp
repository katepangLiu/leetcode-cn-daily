class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> intersect;
        unordered_set<int> numsSet;
        unordered_set<int> memo;
        for( int num : nums1 ) {
            numsSet.insert(num);
        }

        for( int num : nums2 ) {
            if( numsSet.count(num) &&  !memo.count(num) ) {
                memo.insert(num);
                intersect.emplace_back(num);
            }
        }

        return intersect;
    }
};