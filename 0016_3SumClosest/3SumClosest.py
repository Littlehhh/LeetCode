class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        nums.sort()
        Min = float("inf") 
        ans = float("inf") 

        for i in range(len(nums)):
            lo = i+1;
            hi = len(nums)-1
            while lo < hi:
                tmp=0
                S = nums[i]+nums[lo]+nums[hi];
                if S>target:
                    tmp = S-target
                    hi-=1
                elif S<target:
                    tmp = target-S
                    lo+=1
                elif S == target:
                    return target
                if tmp < Min:
                    Min=tmp
                    ans=S
        return ans