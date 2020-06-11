class Solution:
    def exchange(self, nums: List[int]) -> List[int]:
        lo, hi=0, len(nums)-1
        while lo < hi:
            while lo < hi and nums[lo]&1: lo+=1
            while lo < hi and not nums[hi]&1: hi-=1
            nums[lo], nums[hi] = nums[hi], nums[lo]
            lo+=1
            hi-=1
        return nums