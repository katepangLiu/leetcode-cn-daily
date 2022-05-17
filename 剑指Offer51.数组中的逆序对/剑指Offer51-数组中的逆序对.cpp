class Solution {
public:
    vector<int> tmp;
    int ans = 0;
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        ans = 0;
        tmp.resize(n);
        mergeSort(nums, 0, n-1);
        return ans;
    }

    void mergeSort(vector<int>& nums, int l, int r) {
        if( l>=r ) {
            return;
        }

        int mid = l + (r-l+1)/2;
        mergeSort(nums, l, mid-1);
        mergeSort(nums, mid, r);
        merge(nums, l, mid, r);
    }

    void merge(vector<int>& nums, int l, int m, int r) {
        int i = l;
        int j = m;
        int k = l;
        while( i<m && j<=r ) {
            if( nums[i] > nums[j] ) {
                ans += j-k ;
                tmp[k] = nums[j];
                j++;
            } else {
                tmp[k] = nums[i];
                i++;
            }
            k++;
        }
        while( i<m ) {
            tmp[k] = nums[i];
            i++;
            k++;
        }
        while( j<=r ) {
            tmp[k] = nums[j];
            j++;
            k++;
        }

        for( int k=l; k<=r; k++ ) {
            nums[k] = tmp[k];
        }
    }
};