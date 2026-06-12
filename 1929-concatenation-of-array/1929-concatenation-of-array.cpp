class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> ans; 
        bool isSecond = true;
        
        for(int i = 0; i < nums.size(); i++) {
            ans.push_back(nums[i]);
            if (isSecond && i == nums.size() - 1) {
                isSecond = false;
                i = -1;
            }
        }

        return ans;
    }
};