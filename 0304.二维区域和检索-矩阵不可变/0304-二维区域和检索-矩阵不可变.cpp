class NumMatrix {
public:
    vector<vector<int>>preSum;
    NumMatrix(vector<vector<int>>& matrix) {
        if(matrix.empty()){
            return ;
        }
        int n=matrix.size();
        int m=matrix[0].size();
        preSum.resize(n+1);
        for(int i=0;i<n+1;i++){
            preSum[i].resize(m+1);
        }
        if (n> 0) {
            for (int i = 0; i <n; i++) {
                for (int j = 0; j <m; j++) {
                    preSum[i+1][j+1] = preSum[i][j+1] + preSum[i+1][j] - preSum[i][j] + matrix[i][j];
                }
            }
        }
    }
    int sumRegion(int row1, int col1, int row2, int col2) {
        return preSum[row2 + 1][col2 + 1] - preSum[row2 + 1][col1] - preSum[row1][col2 + 1] + preSum[row1][col1];
    }
};