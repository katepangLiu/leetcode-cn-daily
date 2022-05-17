class Solution {
public:
    int numJewelsInStones(string J, string S) {
        set<char> jewels;
        for( char& j : J ) {
            jewels.insert( j );
        }

        int numJewels = 0;
        for( char& s : S) {
            if( jewels.count(s) ) {
                numJewels++;
            }
        }

        return numJewels;
    }
};