class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> res;
        unordered_set<int> set;

        int mine = INT_MAX, maxe = INT_MIN;

        for (int i = 0; i < nums.size(); i++) {
            set.insert(nums[i]);
            mine = min(mine, nums[i]);
            maxe = max(maxe, nums[i]);
        }

        while (mine < maxe) {
            if (set.find(mine) == set.end()) {
                res.push_back(mine);
            }
            mine++;
        }

        return res;
    }
};