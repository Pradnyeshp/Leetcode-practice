class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;
        while (n != 0) {
            n = n & (n - 1); // Remove the last set bit
            count++;
        }
        return count;
    }
};