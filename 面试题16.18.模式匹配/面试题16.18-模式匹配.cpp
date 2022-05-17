class Solution {
public:
    int cnt[2];
    bool patternMatching(string pattern, string value) {
        // 分情况讨论
        // 1. pattern为空
        if (pattern.empty()) return value.empty();
        // 2. pattern不为空
        // 2.1 value为空, 判断pattern是否只由一个字母组成
        if (value.empty()) {
            int i = 0;
            while (i < pattern.size() && pattern[i] == pattern[0]) i ++;
            return i == pattern.size();
        }
        // 2.2 pattern不为空，value不为空
        int n = pattern.size(), m = value.size();
        //   预处理统计a, b字母个数cnt[0], cnt[1]
        cnt[0] = cnt[1] = 0;
        for (auto x: pattern) cnt[x - 'a'] ++;
        //   判断cnt[0], cnt[1]是否有为0的情况
        if (!cnt[0]) return helper(value, cnt[1]);
        else if (!cnt[1]) return helper(value, cnt[0]);

        //  2.2.1 假设使得a,b其中之一为空, 即次数为0
        if (helper(value, cnt[0])) return true;
        if (helper(value, cnt[1])) return true;

        // 2.2.2 a,b都不为空; 枚举a, b匹配的长度，使得a * len_a + b * len_b = m; len_a唯一确定len_b，只需枚举len_a
        for (int len_a = 1; len_a * cnt[0] <= m - cnt[1]; len_a ++) {
            if ((m - len_a * cnt[0]) % cnt[1] != 0) continue;
            int len_b = (m - len_a * cnt[0]) / cnt[1];
            if (check(pattern, value, len_a, len_b)) return true;
        }
        return false;
    }

    bool helper(string value, int k) { // pattern不为空，value不为空. 判断是否可以k次切分value
        int m = value.size();
        if (m % k != 0) return false;
        int len = m / k;
        for (int i = len; i < m; i += len)
            if (value.substr(i, len) != value.substr(0, len)) return false;
        return true;
    }

    bool check(string pattern, string value, int len_a, int len_b) { 
        string ps[2] = {"", ""}; // a, b匹配的字符串
        for (int i = 0, j = 0; i < pattern.size(); i ++) { // i, j指针都是恰当长度的
            if (pattern[i] == 'a') {
                if (ps[0] == "") ps[0] = value.substr(j, len_a);
                else if (value.substr(j, len_a) != ps[0]) return false;
                j += len_a;
            } else if (pattern[i] == 'b') {
                if (ps[1] == "") ps[1] = value.substr(j, len_b);
                else if (value.substr(j, len_b) != ps[1]) return false;
                j += len_b;
            }
        }
        return true;
    }
};