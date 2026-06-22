class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans = 0;
        for (int i: nums) {
            if (numOfDigits(i) % 2 == 0) {
                ans++;
            }
        }
        return ans;
    }

    int numOfDigits(int num) {
        int res = 0;

        while(num > 0) {
            num /= 10;
            res++;
        }
        return res;
    }
};