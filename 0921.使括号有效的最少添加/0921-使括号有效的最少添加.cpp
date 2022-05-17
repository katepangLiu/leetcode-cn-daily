class Solution {
public:
    int minAddToMakeValid(string S) {
        int left = 0;
        int right = 0;
        int count = 0;

        for(char& c : S ) {
            if( c == '(' ) {
                left++;
            } else {
                if( left == 0 ) {
                    count++;
                } else {
                    left--;
                }
            }
        }

        count += left;
        return count;
    }
};