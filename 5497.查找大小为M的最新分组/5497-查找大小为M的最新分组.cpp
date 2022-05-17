class Solution {
public:
    int findLatestStep(vector<int>& arr, int m) {
        int n = arr.size();
        if (n == m) {
            return n;
        }
        
        //span��ÿһ��Ԫ�ش��һ��111����;
        map<int, int> span = {{1, n}};
        
        for (int i = n - 1; i >= 0; --i) {
            //�ҵ���ǰ�任λ������������;
            auto it = prev(span.upper_bound(arr[i]));
            auto [l, r] = *it;
            if (arr[i] - l == m || r - arr[i] == m) {
                return i;
            }
            
            //��λ�ñ�Ϊ0����ǰ����ֿ���2��������;
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