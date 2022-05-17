/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        //���ҵ��ⶥ�±�;
        //��벿�ֶ��ֲ��ң����û���ҵ�target,���Ұ벿�ֶ��ֲ���
        //���߶�δ�ҵ� -1;
        int n = mountainArr.length();
        int peakIdx = getPeakIndex(mountainArr);
        int ans =-1;
        if( peakIdx == -1 ) {
            return -1;
        }
        if( target == mountainArr.get(peakIdx) ) {
            return peakIdx;
        }
        ans = search(mountainArr, target, 0, peakIdx-1, true);
        if( ans == -1 ) {
            ans = search(mountainArr, target, peakIdx+1, n-1, false);
        }
        return ans;
    }

    int getPeakIndex(MountainArray& mountainArr) {
        int n = mountainArr.length();
        int l = 1;
        int r = n-2;
        while(l<=r) {
            int mid = l+ (r-l)/2;
            int cur = mountainArr.get(mid);
            int prev =  mountainArr.get(mid-1);
            int next =  mountainArr.get(mid+1);
            if( cur>prev && cur>next ) {
                return mid;
            } else if( cur>prev ) {
                l = mid+1;
            } else {
                r = mid-1;
            }
        }
        return -1;
    }

    int search(MountainArray& mountainArr, int target, int l, int r, bool up) {
        while( l<=r ) {
            int mid = l + (r-l)/2;
            int cur = mountainArr.get(mid);

            if( cur == target ) {
                return mid;
            }
            if( up ) {
                if( cur < target ) {
                    l = mid+1;
                } else {
                    r = mid-1;
                }
            } else {
                if( cur < target ) {
                    r = mid-1;
                } else {
                    l = mid +1;
                }
            }
        }
        return -1;
    }
};