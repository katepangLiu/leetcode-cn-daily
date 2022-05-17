class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size())
            return findMedianSortedArrays(nums2,nums1);
        
        int size1=nums1.size();
        int size2=nums2.size();
        int begin=0,end=size1;
        int mid1=0/*前一部分的最大值*/,mid2=0/*后一部分的最小值*/;

        while(begin<=end)
        {
            int index1=(begin+end)/2;               /*数组1中分隔线右侧下标*/
            int index2=(size1+size2+1)/2-index1;    /*数组2中分隔线右侧下标，根据公式来计算*/

            int left1=(index1==0?INT_MIN:nums1[index1-1]);       /*数组1中分隔线左侧元素的值*/
            int right1=(index1==size1?INT_MAX:nums1[index1]);    /*数组1中分隔线右侧元素的值*/
            int left2=(index2==0?INT_MIN:nums2[index2-1]);       /*数组2中分隔线左侧元素的值*/
            int right2=(index2==size2?INT_MAX:nums2[index2]);    /*数组2中分隔线右侧元素的值*/

            if(left1<=right2)/*数组2分隔线右侧元素大于数组1分隔线左侧元素*/
            {
                mid1=max(left1,left2);          /*mid1为分隔线左侧元素的较大者*/
                mid2=min(right1,right2);        /*mid2为分隔线右侧元素的较小者*/
                begin=index1+1;
            }
            else
                end=index1-1;
        }

        if( (size1 + size2) %2 == 1 ) {
            return mid1;
        } else {
            return  (double) (mid1+mid2)/2   ;
        }
    }
};