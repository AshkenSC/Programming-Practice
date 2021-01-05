# 198
'''
1) 起点
dp[i][j] = dp[i][j]

2) 只能从左边来
dp[i][j] = dp[i][j - 1]

3) 只能从上边来
dp[i][j] = dp[i - 1][j]

4) 可以从上和左来
dp[i][j] = min(dp[i][j - 1], dp[i - 1][j])


'''

from typing import List

class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])
        dp = [[0] * n for _ in range(m)]
        for i in range(m):
            for j in range(n):
                if i == 0 and j == 0:
                    continue
                elif i == 0:
                    grid[i][j] = grid[i][j - 1] + grid[i][j]
                elif j == 0:
                    grid[i][j] = grid[i - 1][j] + grid[i][j]
                else:
                    grid[i][j] = min(grid[i][j - 1], grid[i - 1][j]) + grid[i][j]
        
        return grid[m - 1][n - 1]
        



sol = Solution()
res = sol.coinChange([2], 3)
print(res)