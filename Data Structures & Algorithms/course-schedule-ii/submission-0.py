class Solution:
    def findOrder(self, n: int, prereq: List[List[int]]) -> List[int]:
        indegree = [0] * n
        adj = [[] for _ in range(n)]
        for c1, c2 in prereq:
            adj[c2].append(c1)
            indegree[c1] += 1
        q = deque()
        for i in range(n):
            if indegree[i] == 0:
                q.append(i)
        ans = []
        while q:
            c = q.popleft()
            ans.append(c)
            for i in adj[c]:
                indegree[i] -= 1
                if indegree[i] == 0:
                    q.append(i)
        if len(ans) == n:
            return ans
        return []