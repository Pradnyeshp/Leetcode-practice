class Solution {
public:
    int firstUniqChar(string s) {
        // map<char, int> mp;
        vector<int> freq(26, 0);

        for (char c : s) {
            // mp[c]++;
            freq[c - 'a']++;
        }

        for (int i = 0; i < s.size(); i++) {
            if (freq[s[i] - 'a'] == 1) {
                return i;
            }
        }
        return -1;
    }
};