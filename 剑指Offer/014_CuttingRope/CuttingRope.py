class Solution1:
    def cuttingRope(self, n: int) -> int:
        if n<=3: return n-1;
        a,b = n//3, n%3
        if b==0: return int(pow(3,a))
        if b==1: return int(pow(3,a-1)*4)
        return int(pow(3,a)*2)


class Solution:
    def cuttingRope(self, n: int) -> int:
        dp = [1]*(n+1)
        for i in range(3, n+1):
            for j in range(1,i):
                dp[i] = max(dp[i], max(j*(i-j), dp[i-j]*j))
        return dp[n]