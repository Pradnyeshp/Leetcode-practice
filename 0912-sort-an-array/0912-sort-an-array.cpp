class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size() - 1;
        ms(nums, 0, n);

        return nums;
    }

    void ms(vector<int>& nums, int l, int r) {
        if (l >= r)
            return;

        int mid = (l + r) / 2;

        ms(nums, l, mid);
        ms(nums, mid + 1, r);
        return mergeArr(nums, l, mid, r);
    }

    void mergeArr(vector<int>& nums, int l, int m, int h) {
        vector<int> temp;
        int left = l, right = m + 1;

        while (left <= m && right <= h) {
            if (nums[left] <= nums[right]) {
                temp.push_back(nums[left++]);
            } else {
                temp.push_back(nums[right++]);
            }
        }

        while (left <= m) {
            temp.push_back(nums[left++]);
        }
        while (right <= h) {
            temp.push_back(nums[right++]);
        }

        for (int i = l; i <= h; i++) {
            nums[i] = temp[i - l];
        }
    }
};