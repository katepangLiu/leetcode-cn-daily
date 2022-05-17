class Solution {
public:
    map<int,int> memo;
public:
    int minDays(int n) {
        return eat(n);
    }
    
    int eat(int n) {
        if( memo.find(n) != memo.end()  ) {
            return memo[n];
        }
        if( n == 0 ) {
            return 0;
        }
        if( n == 1 ) {
            return 1;
        }
        if( n == 2 ) {
            return 2;
        }
        int ans = min( eat(n/3) + eat(n%3)+1, eat(n/2) + eat(n%2) +1);
        memo[n] = ans;
        return ans;
    }
};