class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        heapSort(nums);
        return nums;
    }

    void heapSort(vector<int>& nums) {
        int n = nums.size();
        //初始堆化: 从最后一个非叶子节点开始到叶子节点结束;
        for( int i=(n-2)/2; i>=0; i-- ) {
            heap(nums, i, n-1);
        }

        //将堆顶与无序区间的最后一个元素交换，再堆化保证堆顶为最值;
        for( int i=n-1; i>0; i-- ) {
            swap( nums[0], nums[i]);
            heap(nums, 0, i-1);
        }
    }

    void heap( vector<int>& nums, int start, int end) {
        int parent = start;
        int child = 2*parent+1;
        while( child <= end ) {
            if( child+1 <= end && nums[child+1]>nums[child] ) {
                child = child+1;
            }

            if( nums[child] < nums[parent] ) {
                break;
            }
            
            swap(nums[parent], nums[child]);
            parent = child;
            child = 2*parent+1;
        }
    }
};