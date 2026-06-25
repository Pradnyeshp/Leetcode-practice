class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        int val;

        for (int i = 0; i < nums.size(); i++) {
            pq.push(nums[i]);
        }
        int length = k - 1;
        while (length > 0) {
            pq.pop();
            length--;
        }
        return pq.top();
    }
};