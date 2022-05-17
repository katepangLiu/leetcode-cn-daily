class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size())
            return findMedianSortedArrays(nums2,nums1);
        
        int size1=nums1.size();
        int size2=nums2.size();
        int begin=0,end=size1;
        int mid1=0/*ǰһ���ֵ����ֵ*/,mid2=0/*��һ���ֵ���Сֵ*/;

        while(begin<=end)
        {
            int index1=(begin+end)/2;               /*����1�зָ����Ҳ��±�*/
            int index2=(size1+size2+1)/2-index1;    /*����2�зָ����Ҳ��±꣬���ݹ�ʽ������*/

            int left1=(index1==0?INT_MIN:nums1[index1-1]);       /*����1�зָ������Ԫ�ص�ֵ*/
            int right1=(index1==size1?INT_MAX:nums1[index1]);    /*����1�зָ����Ҳ�Ԫ�ص�ֵ*/
            int left2=(index2==0?INT_MIN:nums2[index2-1]);       /*����2�зָ������Ԫ�ص�ֵ*/
            int right2=(index2==size2?INT_MAX:nums2[index2]);    /*����2�зָ����Ҳ�Ԫ�ص�ֵ*/

            if(left1<=right2)/*����2�ָ����Ҳ�Ԫ�ش�������1�ָ������Ԫ��*/
            {
                mid1=max(left1,left2);          /*mid1Ϊ�ָ������Ԫ�صĽϴ���*/
                mid2=min(right1,right2);        /*mid2Ϊ�ָ����Ҳ�Ԫ�صĽ�С��*/
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