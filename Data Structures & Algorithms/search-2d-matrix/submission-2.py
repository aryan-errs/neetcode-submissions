class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        n,m = len(matrix), len(matrix[0])
        l, h = 0, n-1
        tRow = -1
        while l <= h:
            mid = l + (h-l)//2
            if matrix[mid][0] <= target <= matrix[mid][-1]:
                tRow = mid
                break
            if matrix[mid][-1] < target:
                l = mid+1
            else:
                h = mid-1
        l, h = 0, m-1
        while l <= h:
            mid = l + (h-l) // 2
            if matrix[tRow][mid] == target:
                return True
            if matrix[tRow][mid] < target:
                l = mid + 1
            else:
                h = mid - 1
        return False
            
