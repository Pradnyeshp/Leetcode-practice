class Solution:
    def shortestToChar(self, s: str, c: str) -> List[int]:
        n = len(s)
        ans = [0] * n

        # Pass 1: Left to Right
        pos = -float("inf")
        for i in range(n):
            if s[i] == c:
                pos = i
            ans[i] = i - pos

        # Pass 2: Right to Left
        pos = float("inf")
        for i in range(n - 1, -1, -1):
            if s[i] == c:
                pos = i
            ans[i] = min(ans[i], pos - i)

        return ans
