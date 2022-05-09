/*
 * @lc app=leetcode.cn id=942 lang=rust
 *
 * [942] 增减字符串匹配
 */

// @lc code=start
impl Solution {
    pub fn di_string_match(s: String) -> Vec<i32> {
        let mut ans = vec![0; s.len() + 1];
        let (mut l, mut r) = (0, s.len() as i32);

        s.chars().enumerate().for_each(|(i, b)| if b == 'I' {
            ans[i] = l;
            l += 1
        } else {
            ans[i] = r;
            r -= 1
        });
        ans[s.len()] = l;
        ans
    }
}
// @lc code=end

