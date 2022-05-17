class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        map<int, int> account = {{5, 0}, {10, 0}, {20, 0}};
        for( auto bill : bills ) {
            if( 5 == bill ) {
                account[5]++;
            } else if( 10 == bill ) {
                if( account[5] < 1 ) {
                    return false;
                }
                account[5]--;
                account[10]++;
            } else if( 20 == bill ) {
                if( account[10] > 0 ) {
                    if( account[5] < 1 ) {
                        return false;
                    } else {
                        account[10]--;
                        account[5]--;
                        account[20]++;
                    }
                } else {
                    if( account[5] < 3 ) {
                        return false;
                    } else {
                        account[5] -= 3;
                    }
                }                
            }
        }

        return true;
    }
};