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
