class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n = arr.size();
        if( n==0 ) {
            return 0;
        }
        if( n == 1 ) {
            return arr[0];
        }
        
        if( n == 2 ) {
            return max( arr[0], arr[1]);
        }
        
        list<int> l;
        int maxVal = arr[0];
        for( auto x : arr ) {
            l.push_back(x);
            maxVal = max(maxVal, x);
        }
        
        
        int winTimes = 0;
        while( 1 ) {
            int first = *l.begin();
            auto itSecond = l.begin();
            itSecond++;
            int second = *itSecond;
            if( first>second ) {
                l.erase(itSecond);
                l.push_back(second);
                winTimes++;
            } else {
                l.erase(l.begin());
                l.push_back(first);
                winTimes=1;
            } 
            if( winTimes == k ) {
                return max(first, second);
            }
            if( first == maxVal ) {
                return maxVal;
            }
        }
        
        return 0;
    }

};