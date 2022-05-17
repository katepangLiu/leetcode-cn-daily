class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> ans;
        for (int i = 0, j = A.size() - 1; i <= j; i++) {
            while (i < j && abs(A[i]) < abs(A[j])) {
                ans.push_back(A[j] * A[j]);
                j--;
            }
            ans.push_back(A[i] * A[i]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
