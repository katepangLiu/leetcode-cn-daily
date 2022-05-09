/*
 * @lc app=leetcode.cn id=942 lang=cpp
 *
 * [942] 增减字符串匹配
 */

// @lc code=start
class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n = s.length();
        vector<int> ans(n+1);
        int l = 0;
        int r = n;

        for( int i=0; i<n; i++ ) {
            char c = s[i];
            if( c == 'I' ) {
                ans[i] = l;;
                l++;
            } else {
                ans[i] = r;
                r--;
            }
        }

        ans[n] = l;

        return ans;
    }
};
// @lc code=end

