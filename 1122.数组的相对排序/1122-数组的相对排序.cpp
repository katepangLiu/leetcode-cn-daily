class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> ans;

        set<int> dict;
        for( int x : arr2 ) {
            dict.insert(x);
        }

        unordered_map<int, int> freqInRange;
        map<int, int> freqOutRange;
        for( int x: arr1 ) {
            if( dict.count(x) ) {
                freqInRange[x]++;
            } else {
                freqOutRange[x]++;
            }
        }

        for( int x :arr2 ) {
            while( freqInRange[x]>0 ) {
                ans.push_back(x);
                freqInRange[x]--;
            }
        }

        for( auto [x, count] : freqOutRange ) {
            while( count > 0 ) {
                ans.push_back(x);
                count--;
            }
        }

        return ans;
    }
};