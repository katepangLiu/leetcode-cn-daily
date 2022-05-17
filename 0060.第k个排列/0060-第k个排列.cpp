class Solution {
    //阶乘数组
    vector<int> factorial;

    int n;
    int k;

public:
    string getPermutation(int n, int k) {
        this->n = n;
        this->k = k;
        calculateFactorial(n);
        string buf(n, '0');
        vector<bool> used( n+1,  false);
        dfs(0, buf, used);
        return buf;
    }

    void dfs(int index, string& buf, vector<bool>& used) {
        if( index == n ) {
            return;
        }
         // 计算还未确定的数字的全排列的个数，第 1 次进入的时候是 n - 1
        int cnt = factorial[n - 1 - index];
        for (int i = 1; i <= n; i++) {
            if (used[i]) {
                continue;
            }
            if (cnt < k) {
                k -= cnt;
                continue;
            }

            buf[index] = '0' + i ;
            used[i] = true;
            dfs(index + 1, buf, used);
            return;
        }

    }

    void calculateFactorial(int n) {
        factorial.resize(n+1);
        factorial[0] = 1;
        for( int i=1; i<=n; i++ ) {
            factorial[i] = factorial[i-1]*i ;
            cout << factorial[i] << ',';
        }
        cout << endl;
    }
};