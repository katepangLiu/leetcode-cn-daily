class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int nn = name.length();
        int nt = typed.length();

        int i=0;
        int j=0;
        while( j< nt ) {
            if( i<nn && name[i] == typed[j] ) {
                i++;
                j++;
            } else if( i>0 && name[i-1] == typed[j] ) {
                j++;
            } else {
                return false;
            }
        }

        if( i < nn ) {
            return false;
        }

        return true;
    }
};