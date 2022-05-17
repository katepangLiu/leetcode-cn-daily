/*
* ������Ŀ��һ�ο����Ƴ�������ͬ��ɫ���������ӣ���ÿ��ֻ���Ƴ�һ��������������һ���Ƴ�ͬһ����ɫ���еط�
* ��dp[l][r][k]
  ��ʼ�±�l(��0��ʼ)�������±�r��k��ʾ���±�r�����������k��Ԫ��ֵ��boxes[r]��ͬ���������ֺ�
* ����[l,l+1,������,r-1,r,ֵͬr��ֵͬr��ֵͬr]
  ������3��Ԫ�غ�boxes[r]��ͬ����k==3����ôdp[l][r][3]=dp[l][r-1][0]+4*4
  ��Ϊ��3����[r]��ͬ������������4�����Լ���4*4
** �õ���ʼ������dp[l][r][k]=dp[l][r-1][0]+(k+1)*(k+1)
* �����п�����boxes[l]~boxes[r-1]��Ҳ���ں�boxes[r]��ֵͬ��Ԫ�أ��п��ܻ�ø���Ļ��ֺ�
  ����[l,l+1,������,i,������,r-1,r,ֵͬr��ֵͬr��ֵͬr]������boxes[i]==boxes[r]
  ��ô�������Ƴ�boxes[i+1]~boxes[r-1]����������ʹԭ����dp[l][r][3]��k=3��ĸ��󣬵���r��ø�С�����ǻ��ֺ͸���
  ��˾���Ҫ��boxes[l]~boxes[r-1]���ҵ�boxes[i]==boxes[r]
** ���������Ƴ�boxes[i+1]~boxes[r-1]����һ���ֵ������ֺ���dp[i+1][r-1][0]
  �Ƴ�֮����[l,l+1,������,i,ֵͬi(ԭ����r)��ֵͬi(ԭ����r+1)��ֵͬi(ԭ����r+2)��ֵͬi(ԭ����r+3)]
  ʣ���ⲿ����dp[l][i][k+1]
** �ܺ���������dp[l][r][k]=max(dp[l][r][k],dp[i+1][r-1][0]+dp[l][i][k+1])
* ���Ĵ𰸾���dp[0][boxes.size()-1][0]
*/
class Solution {
    int dp[100][100][100];
public:
    int removeBoxes(vector<int>& boxes) {
        int n=boxes.size();
        memset(dp,0,sizeof(dp));
        return dfs(boxes, 0, n-1, 0);
    }

    int dfs(vector<int>& boxes, int l, int r, int k) {
        if( l > r ) {
            return 0;
        }

        if( dp[l][r][k] != 0 ) {
            return dp[l][r][k];
        }

        while( l<r && boxes[r-1] == boxes[r] ) {
            r--;
            k++;
        }

        dp[l][r][k] = dfs(boxes, l, r-1, 0) + (k+1)*(k+1);
        for(int i=l; i<r; i++) {
            if( boxes[i] == boxes[r] ) {
                //�Ƴ� [i+1, .., r-1],�� i,r����,�ӳɸ�����������;
                int score = dfs(boxes,i+1,r-1,0) + dfs(boxes,l,i,k+1);
                dp[l][r][k] = max( dp[l][r][k], score);
            }
        }

        return dp[l][r][k];
    }
};