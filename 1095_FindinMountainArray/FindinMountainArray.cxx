
// This is the MountainArray's API interface.
// You should not implement it, or speculate about its implementation
class MountainArray {
  public:
    int get(int index);
    int length();
};


class Solution1 {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int peak = findPeak(mountainArr);
        int lo = 0;
        int hi = peak;
        while(lo < hi){
            int mid = lo + (hi-lo) / 2;
            int midVal = mountainArr.get(mid);
            if(midVal < target){
                lo = mid + 1;
            }
            else{
                hi = mid;
            }
        }
        if(lo < mountainArr.length() && mountainArr.get(lo) == target) return lo;
        lo = peak;
        hi = mountainArr.length();
        while(lo < hi){
            int mid = lo + (hi-lo) / 2;
            int midVal = mountainArr.get(mid);
            if(midVal > target){
                lo = mid + 1;
            }
            else{
                hi = mid;
            }
        }
        return lo < mountainArr.length() && mountainArr.get(lo) == target ? lo : -1;
    }
    int findPeak(MountainArray &mountainArr){
        int lo = 0;
        int hi = mountainArr.length();
        while(lo < hi){
            int mid = lo + (hi-lo) / 2;
            int midVal = mountainArr.get(mid);
            if(mid==mountainArr.length()-1){
                return midVal < mountainArr.get(mid-1) ? mid-1:mid;
            } 
            if(mid==0){
                return midVal < mountainArr.get(mid+1) ? mid+1:mid;
            } 
            int midLeftVal = mountainArr.get(mid-1);
            int midRightVal = mountainArr.get(mid+1);
            if(midLeftVal < midVal && midVal < midRightVal){
                lo = mid+1;
            }
            if(midLeftVal > midVal && midVal > midRightVal){
                hi = mid;
            }
            if(midLeftVal < midVal && midVal > midRightVal){
                return mid;
            }
        }
        return lo;
    }
};


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
        int peak = findPeak(mountainArr);
        int lo = 0;
        int hi = peak;
        int mid;
        while(lo < hi){
            mid = lo + (hi-lo) / 2;
            if(mountainArr.get(mid) < target){
                lo = mid + 1;
            }
            else{
                hi = mid;
            }
        }
        if(lo < mountainArr.length() && mountainArr.get(lo) == target) return lo;
        lo = peak;
        hi = mountainArr.length();
        while(lo < hi){
            mid = lo + (hi-lo) / 2;
            if(mountainArr.get(mid) > target){
                lo = mid + 1;
            }
            else{
                hi = mid;
            }
        }
        return lo < mountainArr.length() && mountainArr.get(lo) == target ? lo : -1;
    }
    int findPeak(MountainArray &mountainArr){
        int lo = 0;
        int hi = mountainArr.length();
        while(lo < hi){
            int mid = lo + (hi-lo) / 2;
            if(mountainArr.get(mid-1) < mountainArr.get(mid)){
                lo = mid+1;
            }
            else{
                hi = mid;
            }
        }
        return lo;
    }
};
