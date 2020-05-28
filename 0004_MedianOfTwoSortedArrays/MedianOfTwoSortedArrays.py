from typing import List

#  O(m+n)
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        All = list()
        while nums1 and nums2:
            if nums1[-1]>nums2[-1]:
                All.append(nums1[-1])
                nums1.pop()
            else:
                All.append(nums2[-1])
                nums2.pop()
        if nums1:
            All.extend(nums1[::-1])
        if nums2:
            All.extend(nums2[::-1])
        count = len(All)
        if count % 2 == 0:
            return (All[int(count/2)]+All[int(count/2)-1])/2
        else:
            return float(All[int(count/2)])

#  O(log(min(m,n)))
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        if len(nums1) > len(nums2):
            # nums1, nums2 = nums2, nums1
            return self.findMedianSortedArrays(nums2, nums1)
        total_mid = (len(nums1)+len(nums2)+1) // 2
        
        lo, hi = 0, len(nums1)
        while lo < hi:
            mid = lo+ (hi-lo) // 2
            remain = total_mid - mid
            if nums1[mid] < nums2[remain-1]:
                lo = mid+1
            else:
                hi = mid
        
        mid, remain = lo, total_mid-lo
        
        max_left = max( float('-inf') if mid <= 0 else nums1[mid-1],
                        float('-inf') if remain <= 0 else nums2[remain-1])
        if (len(nums1)+len(nums2)) & 1:
            return max_left
        min_right = min( float('inf') if mid >= len(nums1)  else nums1[mid],
                        float('inf') if remain >= len(nums2) else nums2[remain])
        return (min_right+max_left) / 2
