class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxHeight = 0;
        int sum = 0;
        for (int i : gain) {
            sum += i;
            maxHeight = max(maxHeight, sum);
        }
        return maxHeight;
    }
};