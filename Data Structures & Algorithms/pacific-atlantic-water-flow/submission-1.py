class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        n, m = len(heights), len(heights[0])
        pacific = {}
        atlantic = {}
        q = deque()
        delr = [0, -1, 0, 1]
        delc = [-1, 0, 1, 0]
        def pacificFlow():
            q = deque()
            for i in range(n):
                q.append([i, 0])
            for i in range(m):
                q.append([0, i])
            while q:
                r, c = q.popleft()
                pacific[(r,c)] = 1
                for i in range(4):
                    nr = r + delr[i]
                    nc = c + delc[i]
                    if 0 <= nr < n and 0 <= nc < m and (nr,nc) not in pacific and heights[nr][nc] >= heights[r][c]:
                        q.append([nr,nc])
        def atlanticFlow():
            q = deque()
            for i in range(n):
                q.append([i, m-1])
            for i in range(m):
                q.append([n-1, i])
            while q:
                r, c = q.popleft()
                atlantic[(r,c)] = 1
                for i in range(4):
                    nr = r + delr[i]
                    nc = c + delc[i]
                    if 0 <= nr < n and 0 <= nc < m and (nr,nc) not in atlantic and heights[nr][nc] >= heights[r][c]:
                        q.append([nr,nc])
        pacificFlow()
        atlanticFlow()
        res = []
        for i in range(n):
            for j in range(m):
                if (i, j) in pacific and (i,j) in atlantic:
                    res.append([i,j])
        return res
                    
