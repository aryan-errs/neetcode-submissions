class Solution:
    def canFinish(self, n: int, prereq: List[List[int]]) -> bool:
        adj = [[] for _ in range(n)]
        indegree = [0] * n
        for c1, c2 in prereq:
            adj[c2].append(c1)
            indegree[c1] += 1
        q = deque()
        for i in range(n):
            if indegree[i] == 0:
                q.append(i)
        cnt = 0
        while q:
            c = q.popleft()
            cnt += 1
            for i in adj[c]:
                indegree[i] -= 1
                if indegree[i] == 0:
                    q.append(i)
        return cnt == n