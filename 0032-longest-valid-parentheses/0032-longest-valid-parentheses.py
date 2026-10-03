class Solution:
    def longestValidParentheses(self, s):
        stack, res, s = [0], 0, ")" + s
        for i in range(1, len(s)):
            if s[i] == ")" and s[stack[-1]] == "(":
                stack.pop()
                res = max(res, i - stack[-1])
            else:
                stack.append(i)
        return res
