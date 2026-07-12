class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        int ans = 0;
        vector<vector<int>> comb;

        sort(nums.begin(), nums.end());

        for (auto i : nums) {
            int start = i[0];
            int end = i[1];
            if (comb.size() == 0 || comb.back()[1] < start) {
                comb.push_back(i);
            }
            if (comb.back()[1] >= start) {
                comb.back()[1] = max(end, comb.back()[1]);
            }
        }

        for (auto i : comb) {
            ans += i[1] - i[0] + 1;
        }

        return ans;
    }
};