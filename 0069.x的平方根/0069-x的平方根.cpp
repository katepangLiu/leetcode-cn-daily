class Solution {
public:

    int mySqrt(int x) {
        int l=0;
        int r=x;
        int mid=0;
        int ans =0;

        while( l <= r ){
            mid = (l+r)/2;
            if(guess(mid, x)){
                l = mid+1;
                ans = mid;
            }else{
                r = mid-1;
            }
        }

        return ans;

    }

    bool guess(int g, int target){
        return (double)g*g <= target;
    }

};