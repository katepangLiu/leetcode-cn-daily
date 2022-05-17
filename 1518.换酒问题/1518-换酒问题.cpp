class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int numWaterBottles = 0;
        int numEmptyBottles = 0;
        while( numBottles>0 ) {
            numWaterBottles += numBottles;
            numEmptyBottles += numBottles;
            numBottles = numEmptyBottles/numExchange;
            numEmptyBottles = numEmptyBottles%numExchange;
        }
            
        return numWaterBottles;
    }
};