class Solution {
public:
    int minArray(vector<int>& numbers) {
        int n = numbers.size();
        if( n== 0) {
            return 0;
        }
        int minIndex = 0;
        for( int i=0; i<n-1; i++ ) {
            if( numbers[i] > numbers[i+1] ) {
                minIndex = i+1;
                break;
            }
        }
        return numbers[minIndex];
    }
};