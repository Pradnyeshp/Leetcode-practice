class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                return mid;
            }

            // left half is sorted
            if (nums[left] <= nums[mid]) {
                if (nums[left] <= target && target < nums[mid]) {
                    // target is in the left half
                    right = mid - 1;
                } else {
                    // target is in the right half
                    left = mid + 1;
                }
            } else {
                // right half is sorted
                if (nums[mid] < target && target <= nums[right]) {
                    // target is in the right half
                    left = mid + 1;
                } else {
                    // target is in the left half
                    right = mid - 1;
                }
            }
        }

        return -1;
    }
};