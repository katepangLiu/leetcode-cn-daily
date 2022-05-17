class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> countMap;
        unordered_set<int> countSet;

        for( int num : arr ) {
            countMap[num]++;
        }


        for( auto [num, count] : countMap ) {
            if( countSet.count(count) ) {
                return false;
            }
            countSet.insert(count);
        }

        return true;
    }
};