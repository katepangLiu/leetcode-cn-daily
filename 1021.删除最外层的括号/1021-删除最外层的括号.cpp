class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        stack<char> st;
        for( char c : s ) {
            if( c == ')' ) {
                st.pop();
            }
            if( !st.empty() ) {
                ans.push_back(c);
            }

            if( c == '(' ) {
                st.push(c);
            }
        }

        return ans;
    }
};