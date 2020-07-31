class Solution1:
    def integerBreak(self, n: int) -> int:
        if n <= 3: return n-1
        def fastPow(base, power):
            result = 1
            while power > 0:
                if power % 2 == 1:
                    result *= base
                power //= 2
                base *= base
            return result

class Solution:
    def integerBreak(self, n: int) -> int:
        dp = [1]*(n+1)

        for i in range(3, n+1):
            for j in range(1, i):
                dp[i] = max(dp[i], j*max(i-j, dp[i-j]))
        return dp[-1]
