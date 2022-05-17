class Solution {
public:
    int dp[500][500];
    int acc[501]; //�ۼӺ�
    int stoneGameV(vector<int>& stoneValue) {
        int size = stoneValue.size();
        //��ֻ��������ʱ��ֻ�ܻ����С���Ľ��
        for(int i = 1; i < size; i++){
            dp[i-1][i] = min(stoneValue[i-1], stoneValue[i]);
        }
        //�ۼ����
        acc[1] = stoneValue[0];
        for(int i = 2; i <= size; i++)
            acc[i] = acc[i-1] + stoneValue[i-1];
        // for(const auto v: acc) cout << v << " ";
        for(int len = 2; len < size; len ++){
            for(int i = 0; i < size - len; i++){
                int j = i+len;
                //�� i->j ��ϸ��С����
                for(int k = i; k < j; k++){
                    int left = acc[k+1]-acc[i];
                    int right = acc[j+1] - acc[k+1];
                    //��������ʹ�ѡ�ұߣ���֮�෴����������ȣ�max(left + dp[i][k], right + dp[k+1][j])
                    if(left > right) dp[i][j] = max(dp[i][j], right + dp[k+1][j]);
                    else if(left < right) dp[i][j] = max(dp[i][j],left + dp[i][k]);
                    else{
                        dp[i][j] = max(dp[i][j], max(left + dp[i][k], right + dp[k+1][j]));
                    }
                }
            }
        }
        return dp[0][size-1];
    }
};