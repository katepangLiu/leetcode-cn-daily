class Solution {
public:
    int cnt[2];
    bool patternMatching(string pattern, string value) {
        // ���������
        // 1. patternΪ��
        if (pattern.empty()) return value.empty();
        // 2. pattern��Ϊ��
        // 2.1 valueΪ��, �ж�pattern�Ƿ�ֻ��һ����ĸ���
        if (value.empty()) {
            int i = 0;
            while (i < pattern.size() && pattern[i] == pattern[0]) i ++;
            return i == pattern.size();
        }
        // 2.2 pattern��Ϊ�գ�value��Ϊ��
        int n = pattern.size(), m = value.size();
        //   Ԥ����ͳ��a, b��ĸ����cnt[0], cnt[1]
        cnt[0] = cnt[1] = 0;
        for (auto x: pattern) cnt[x - 'a'] ++;
        //   �ж�cnt[0], cnt[1]�Ƿ���Ϊ0�����
        if (!cnt[0]) return helper(value, cnt[1]);
        else if (!cnt[1]) return helper(value, cnt[0]);

        //  2.2.1 ����ʹ��a,b����֮һΪ��, ������Ϊ0
        if (helper(value, cnt[0])) return true;
        if (helper(value, cnt[1])) return true;

        // 2.2.2 a,b����Ϊ��; ö��a, bƥ��ĳ��ȣ�ʹ��a * len_a + b * len_b = m; len_aΨһȷ��len_b��ֻ��ö��len_a
        for (int len_a = 1; len_a * cnt[0] <= m - cnt[1]; len_a ++) {
            if ((m - len_a * cnt[0]) % cnt[1] != 0) continue;
            int len_b = (m - len_a * cnt[0]) / cnt[1];
            if (check(pattern, value, len_a, len_b)) return true;
        }
        return false;
    }

    bool helper(string value, int k) { // pattern��Ϊ�գ�value��Ϊ��. �ж��Ƿ����k���з�value
        int m = value.size();
        if (m % k != 0) return false;
        int len = m / k;
        for (int i = len; i < m; i += len)
            if (value.substr(i, len) != value.substr(0, len)) return false;
        return true;
    }

    bool check(string pattern, string value, int len_a, int len_b) { 
        string ps[2] = {"", ""}; // a, bƥ����ַ���
        for (int i = 0, j = 0; i < pattern.size(); i ++) { // i, jָ�붼��ǡ�����ȵ�
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