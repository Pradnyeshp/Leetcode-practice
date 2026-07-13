class Solution:
    def specialNodes(
        self, n: int, edges: List[List[int]], x: int, y: int, z: int
    ) -> int:
        adj = defaultdict(list)
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)

        def bfs(node: int) -> list[int]:
            dist = [-1] * n
            dist[node] = 0

            queue = deque([node])
            while queue:
                u = queue.popleft()
                for v in adj[u]:
                    # Check if this neighbour was not visited yet
                    if dist[v] == -1:
                        dist[v] = dist[u] + 1
                        queue.append(v)

            return dist

        # Calculate distances from every node to x, y and z
        dx, dy, dz = bfs(x), bfs(y), bfs(z)

        result = 0
        for i in range(n):
            a, b, c = sorted([dx[i], dy[i], dz[i]])  # Ensure a <= b <= c
            result += int(a * a + b * b == c * c)

        return result
