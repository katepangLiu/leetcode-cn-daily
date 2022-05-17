class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t buf = 0;
        int step = 0;
        reverse(n, buf, step);
        cout << buf << endl;
        cout << step << endl;
        
        if( step == 0 ) {
            return 0;
        }

        buf = buf << (32 - step);
        return buf;
    }

    void reverse(uint32_t left, uint32_t& buf, int& step) {
        if( left <= 0 ) {
            return;
        }

        step++;
        buf = buf*2 + left%2;
        left = left/2;
        reverse(left, buf, step);
    }
};