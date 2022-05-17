class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int i=0;
        bool end = false;

        if( strs.size() < 1 ) {
            return "";
        }

        for( ; i< strs[0].size(); i++ ) {
            for( int j=1; j< strs.size(); j++ ) {
                if( strs[0][i] != strs[j][i] ) {
                    end = true;
                    break;
                }
            } 
            if( end ) {
                break;
            }
        }

        if( strs[0].size() <1 ) {
            return "";
        }
        return strs[0].substr( 0, i );
    }
};