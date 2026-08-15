class Solution:
    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        n = len(isConnected)
        p = [i for i in range(n)]
        r = [1] * n

        def find(n1):
            res = n1

            while res != p[res]:
                p[res] = p[p[res]]
                res = p[res]

            return res

        def union(n1, n2):
            p1, p2 = find(n1), find(n2)

            if p1 == p2:
                return 0

            if r[p1] > r[p2]:
                r[p1] += r[p2]
                p[p2] = p1
            else:
                r[p2] += r[p1]
                p[p1] = p2

            return 1

        res = n
        for i in range(n):
            for j in range(n):
                if isConnected[i][j] == 1:
                    res -= union(i, j)

        return res
