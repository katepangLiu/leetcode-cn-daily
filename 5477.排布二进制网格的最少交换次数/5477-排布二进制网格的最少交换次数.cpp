class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> suffixZeros(n);
        int swapStep = 0;

        for( int i=0; i<n; i++ ) {
            int suffixZero = 0;
            for( int j=n-1; j>=0; j-- ) {
                if( grid[i][j] != 0 ) {
                    break;
                }
                suffixZero++;
            }
            suffixZeros[i] = suffixZero;
        }

        for( int i=0; i<n-1; i++ ) {
            int j=i ;
            int targetSuffixZeros = n-i-1;

            //���������ҵ���һ������i���������; 
            //  �Ҳ������޽⣬����-1; 
            //  �ҵĵ����������Ͻ��ҵ����л��� i �У��ۼƽ�������;
            for( ; j<n; j++) {
                if( suffixZeros[j] >= targetSuffixZeros  ) {
                    break;
                }
            }
            if( j == n ) {
                return -1;
            }
            for( ; j>i; j--) {
                swap(suffixZeros[j], suffixZeros[j-1]);
                swapStep++;
            }
        }

        return swapStep;
    }
};