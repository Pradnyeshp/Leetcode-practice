class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int lm = height[l], rm = height[r];
        int sum = 0;

        while (l < r) {
            if (lm < rm) {
                l++;
                lm = max(lm, height[l]);
                sum += lm - height[l];
            } else {
                r--;
                rm = max(rm, height[r]);
                sum+= rm - height[r];
            }
        }

        return sum;
    }
};