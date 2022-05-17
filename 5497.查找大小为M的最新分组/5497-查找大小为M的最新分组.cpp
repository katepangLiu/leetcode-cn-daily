class Solution {
public:
    int findLatestStep(vector<int>& arr, int m) {
        int n = arr.size();
        if (n == m) {
            return n;
        }
        
        //span的每一个元素存放一个111序列;
        map<int, int> span = {{1, n}};
        
        for (int i = n - 1; i >= 0; --i) {
            //找到当前变换位置所属的区间;
            auto it = prev(span.upper_bound(arr[i]));
            auto [l, r] = *it;
            if (arr[i] - l == m || r - arr[i] == m) {
                return i;
            }
            
            //该位置变为0，当前区间分开成2个子区间;
            span.erase(it);            
            if (l <= arr[i] - 1) {
                span.emplace(l, arr[i] - 1);
            } 
            if (arr[i] + 1 <= r) {
                span.emplace(arr[i] + 1, r);
            } 
        }
        return -1;
    }
};