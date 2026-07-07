// You keep track of the farthest index you can reach so far (maxIndex).
// Scan the array left → right:

// If at any time maxIndex already reaches or passes the last index, you can
// finish → return true.

// If you land on a position i where nums[i] == 0 and maxIndex == i, you’re
// stuck (you can’t jump further) → return false.

// Otherwise, keep extending your reach: maxIndex = max(maxIndex, i + nums[i]).

// If you finish the loop without getting stuck, return true.

// Time: O(n) — single pass over the array.
//  Space: O(1) — constant extra variables.

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxIndex = nums[0];

        for (int i = 0; i < nums.size() - 1; i++) {
            if (maxIndex >= nums.size() - 1) {
                return true;
            }
            if (nums[i] == 0 && maxIndex == i) {
                return false;
            }
            maxIndex = max(maxIndex, i + nums[i]);
        }
        return true;
    }
};
