class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        int64_t sum = 0;
        int len1 = nums1.size();
        int len2 = nums2.size();

        vector<vector<int>> join;
        int i = 0;
        int j = 0;
        while (i < len1 && j < len2) {
            if (nums1[i] == nums2[j]) {
                join.push_back({ i, j });
                i++;
                j++;
            }
            else if (nums1[i] < nums2[j]) {
                i++;
            }
            else {
                j++;
            }
        }

        //添加辅助位置，为了在循环体里计算所有区间的和，包括最后一个区间;
        join.push_back({ len1, len2 } );
        
        int start1 = 0;
        int start2 = 0;
        for (int k = 0; k < join.size(); k++) {
            int64_t sum1 = sumNums(nums1, start1, join[k][0]);
            int64_t sum2 = sumNums(nums2, start2, join[k][1]);
            start1 = join[k][0];
            start2 = join[k][1];
            sum += max(sum1, sum2);
        }

        return sum % 1000000007;
    }

    int64_t sumNums(vector<int>& nums, int start, int end) {
        int64_t sum = 0;
        for (int i = start; i < end; i++) {
            sum += nums[i];
        }
        return sum;
    }
};