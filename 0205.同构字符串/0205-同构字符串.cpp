class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, int> dicts;
        map<char, int> dictt;
        int vals = -1;
        int valt = -1;
        int n = s.length();

        for( int i=0; i<n; i++ ) {
            if( dicts.count(s[i]) == 0) {
                vals++;
                dicts[s[i]] = vals;
            }
            if( dictt.count(t[i]) == 0) {
                valt++;
                dictt[t[i]] = valt;
            }
            if( dicts[s[i]] != dictt[t[i]] ) {
                //cout << i << ','<< dicts[s[i]] << ','<< dictt[s[i]] <<   endl;
                return false;
            }
        }

        return true;
    }
};