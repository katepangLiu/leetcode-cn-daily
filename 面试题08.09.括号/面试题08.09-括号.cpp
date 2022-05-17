class Solution {
public:
    vector<string> ans;    
public:
    vector<string> generateParenthesis(int n) {
        backtrace(n, 0, 0, "");
        return ans;
    }

    void backtrace(int n, int left, int right, string tmp) {
        if( left == n && right == n ) {
            ans.push_back(tmp);
        }

        if( left < n ) {
            backtrace( n, left+1, right, tmp + "(" );
        }
        if( right < left && right < n ) {
            backtrace( n, left, right+1, tmp + ")" );
        }
    }
};