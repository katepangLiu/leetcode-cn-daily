class Solution {
public:
    int scoreOfParentheses(string S) {
        stack<int> st;
        st.push(0);

        for( char& c : S ) {
            if( c == '(' ) {
                st.push(0);
            } else {
                int subScore = st.top();
                st.pop();
                int score = st.top();
                st.pop();
                score += max(1, 2*subScore);
                st.push(score);
            }
        }
        int score = st.top();
        st.pop();
        return score;
    }
};