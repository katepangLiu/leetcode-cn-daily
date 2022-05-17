class Solution {
public:
    string reverseWords(string s) {
        string ans;
        stack<char> st;

        for(char c : s ) {
            if( c != ' ' ) {
                st.push(c);  
            } else {
                while( !st.empty() ) {
                    ans.push_back(st.top());
                    st.pop();
                }
                ans.push_back(' ');
            }
        }    
        while( !st.empty() ) {
            ans.push_back(st.top());
            st.pop();
        }

        return ans;   
    }
};