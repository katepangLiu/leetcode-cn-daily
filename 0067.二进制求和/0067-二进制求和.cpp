class Solution {
public:
    string addBinary(string a, string b) {
        string* pRes;
        if (a.length() >= b.length()) {
            pRes = &a;
        }
        else {
            pRes = &b;
        }
        int i = a.size()-1;
        int j = b.size()-1;
        int k = max(i, j);
        int digit = 0;

        for (; i >= 0 || j >= 0; i--, j--) {
            int aVal = i >= 0 ? a[i] -'0' : 0;
            int bVal = j >= 0 ? b[j] -'0' : 0;
            digit += aVal + bVal;
            (*pRes)[k] = digit % 2 + '0';
            digit /= 2;
            k--;
        }

        if (digit) {
            return "1" + *pRes;
        }
        return *pRes;
    }
};