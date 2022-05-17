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

            //从上往下找到第一个符合i行需求的行; 
            //  找不到则无解，返回-1; 
            //  找的到，从下往上将找到的行换到 i 行，累计交换步数;
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