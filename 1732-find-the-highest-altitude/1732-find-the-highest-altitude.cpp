class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxHeight = INT_MIN;
        int sum = 0;
        for (int i : gain) {
            sum += i;
            maxHeight = max(maxHeight, sum);
        }
        if (maxHeight < 0) {
            return 0;
        }

        return maxHeight;
    }
};