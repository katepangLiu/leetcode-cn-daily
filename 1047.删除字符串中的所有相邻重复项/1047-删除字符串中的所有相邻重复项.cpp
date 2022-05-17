class Solution {
public:
    string removeDuplicates(string S) {
        string st;
        for(char c : S ) {
            if( !st.empty() && st.back() == c) {
                st.pop_back();
            } else {
                st.push_back(c);
            }
        }

        return st;
    }
};