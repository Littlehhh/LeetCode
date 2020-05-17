class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        if not nums:
            return 0
        MAX = nums[0]
        MIN = nums[0]
        ans = nums[0]
        for n in nums[1:]:
            if n < 0:
                MAX, MIN = MIN, MAX
            MAX = max(n*MAX, n)
            MIN = min(n*MIN, n)
            ans = max(MAX, ans)
        return ans