class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n = arr.size();
        if( n < 3 ) {
            return false;
        }
        int odd0= arr[0]%2;
        int odd1= arr[1]%2;
        
        for( int i=2; i<n; i++) {
            int odd = arr[i]%2;
            if( odd0 && odd1 && odd ) {
                return true;
            }
            odd0 = odd1;
            odd1 = odd;
        }     
        
        return false;
    }
};