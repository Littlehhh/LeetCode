class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        if obstacleGrid[0][0]:
            return 0
        m = len(obstacleGrid)
        n = len(obstacleGrid[0])
        dp = [[0]* n for _ in range(m)]
        dp[0][0] = 1

        for i in range(1, n):
            if not obstacleGrid[0][i]:
                dp[0][i] = dp[0][i-1]
        for i in range(1, m):
            if not obstacleGrid[i][0]:
                dp[i][0] = dp[i-1][0]


        for i in range(1, m):
            for j in range(1, n):
                if not obstacleGrid[i][j]:
                    dp[i][j] = dp[i-1][j] + dp[i][j-1]
        return dp[-1][-1]

