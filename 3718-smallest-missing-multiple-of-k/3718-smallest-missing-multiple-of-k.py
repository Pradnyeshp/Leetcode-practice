class Solution:
    def missingMultiple(self, nums: List[int], k: int) -> int:
        s = set(nums)
        temp = k

        while temp in s:
            temp = temp + k

        return temp
