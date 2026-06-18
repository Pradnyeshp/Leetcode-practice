class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        double maxA = 0;

        while(l < r) {
            int w = r - l;
            int h = min(height[r], height[l]);
            double area = w * h;

            maxA = max(area, maxA);

            if(height[r] < height[l]) {
                r--;
            } else {
                l++;
            }
        }

        return maxA;
    }
};