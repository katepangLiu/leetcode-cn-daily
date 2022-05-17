class NumArray {
private:
    vector<int> prevSum;

public:
    NumArray(vector<int>& nums) {
        int n = nums.size();
        prevSum.resize(n+1);
        for( int i=0; i<n; i++ ) {
            prevSum[i+1] = prevSum[i] + nums[i];
        }
    }
    
    int sumRange(int i, int j) {
        return prevSum[j+1] - prevSum[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */