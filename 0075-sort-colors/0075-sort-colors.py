class Solution:
    def sortColors(self, nums: List[int]) -> None:
        # low: next spot for 0 | mid: current element | high: next spot for 2
        low, mid, high = 0, 0, len(nums) - 1

        while mid <= high:
            if nums[mid] == 0:
                # Send 0 to the left (low) and advance both pointers
                nums[low], nums[mid] = nums[mid], nums[low]
                low += 1
                mid += 1
            elif nums[mid] == 1:
                # 1 is already in the correct middle section, just move forward
                mid += 1
            else:  # nums[mid] == 2
                # Send 2 to the right (high) and shrink high boundary
                nums[high], nums[mid] = nums[mid], nums[high]
                high -= 1
                # Note: mid is NOT incremented here because the swapped
                # value from high still needs to be evaluated in the next iteration.
