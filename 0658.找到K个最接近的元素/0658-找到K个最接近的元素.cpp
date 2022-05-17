class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ans;
        int n =arr.size();
        int l = 0;
        int r = n-1;

        //先找到 x 在 arr 中的位置
        //再像左右移动直到个数为k

        while( l < r ) {
            int mid = l + (r-l+1)/2;
            if( arr[mid] > x ) {
                r = mid-1;
            } else {
                l = mid;
            }
        }

        //return {arr[l]};

        int count = 0;
        r = l +1;
        while( l>=0 && r<n && count<k ) {
            if( abs(arr[l] -x) > abs(arr[r]-x) ) {
                ans.push_back(arr[r]);
                r++;
            } else {
                ans.push_back(arr[l]);
                l--;
            }
            count++;
        }

        while( l>=0 && count< k  ) {
            ans.push_back(arr[l]);
            count++;
            l--;
        }

        while( r<n && count < k ) {
            ans.push_back(arr[r]);
            count++;
            r++;
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};