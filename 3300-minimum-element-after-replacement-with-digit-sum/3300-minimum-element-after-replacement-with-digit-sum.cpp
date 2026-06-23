class Solution {
public:
    int minElement(vector<int>& nums) {
        int res = INT_MAX;
        for (int i : nums) {
            int sum = getSum(i);
            res = min(sum, res);
        }
        return res;
    }

    int getSum(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
};