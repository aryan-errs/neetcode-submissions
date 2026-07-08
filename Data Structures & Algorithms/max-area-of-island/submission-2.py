class Solution:
    def solve(self, row:int, col:int, grid: List[List[int]]) -> int:
        if row < 0 or row >= len(grid) or col < 0 or col >= len(grid[0]) or grid[row][col] == 0:
            return 0
        grid[row][col] = 0
        a2 = self.solve(row-1, col, grid)
        a1 = self.solve(row + 1, col, grid)
        a3 = self.solve(row, col+1, grid)
        a4 = self.solve(row, col-1, grid)
        # maxArea = max(maxArea, 1+a1+a2+a3+a4)
        return 1 + a1 + a2 + a3 + a4
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        maxArea = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 1:
                    maxArea = max(maxArea, self.solve(i,j,grid))
        return maxArea