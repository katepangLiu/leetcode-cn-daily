class Solution {
public:
    bool isValid(string s) {
        map<char, int> dict= { {'(',1},{')',-1}, {'{', 2},{'}', -2}, {'[',3}, {']', -3}  };
        stack<int> st;
        st.push(0);

        for( char c : s ) {
            if( dict[c] > 0 ) {
                st.push(dict[c]);
            } else {
                if( st.top() + dict[c] != 0 ) {
                    return false;
                } else {
                    st.pop();
                }
            }
        }

        if( st.top() == 0 ) {
            return true;
        }
        return false;
    }
};