class Solution:
    def validTree(self, n: int, edges: List[List[int]]) -> bool:
        adj = [[] for _ in range(n)]
        for edge in edges:
            adj[edge[0]].append(edge[1])
            adj[edge[1]].append(edge[0])
        q = deque()
        q.append((0,-1))
        vis = [0] * n
        vis[0] = 1
        while q:
            print(q)
            curr, parent = q.popleft()
            for node in adj[curr]:
                if not vis[node]:
                    vis[node] = 1
                    q.append((node, curr))
                elif node != parent:
                    return False  
        for i in range(n):
            if not vis[i]:
                return False              
        return True
