class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort( arr.begin(), arr.end() );
        vector<vector<int>> ans;
        int minDiff = INT_MAX;        
        for( int i=1; i< arr.size(); i++ ) {
            int diff = arr[i] - arr[i-1];
            
            if( diff < minDiff ) {
                minDiff = diff;
                ans.clear();  
            }

            if( diff == minDiff ) {
                vector<int> pair = {arr[i-1], arr[i]};
                ans.push_back(pair);
            }
        }

        return ans;
    }
};