class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort( piles.begin(), piles.end() );
        int n = piles.size();
        int left = 0;
        int right = n-1;
        int coins = 0;
        
        while( left < right ) {
            coins += piles[right-1];
            left++;
            right -=2;
        }
        
        return coins;
    }
};