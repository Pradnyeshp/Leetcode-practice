class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        vector<int> freq(26, 0);
        vector<int> actual(26, 0);
        int ans = INT_MAX;

        for (char c : target) {
            freq[c - 'a']++;
        }

        for (char c : s) {
            actual[c - 'a']++;
        }

        for (int i = 0; i < 26; i++) {
            if (freq[i] != 0) {
                int curr = actual[i] / freq[i];
                ans = min(ans, curr);
            }
        }
        return ans;
    }
};