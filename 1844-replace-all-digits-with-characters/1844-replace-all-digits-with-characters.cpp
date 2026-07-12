class Solution {
public:
    string replaceDigits(string s) {
        for (int i = 1; i < s.size(); i += 2) {
            int cnt = (s[i] - '0') % 26;
            char prev = s[i - 1];
            s[i] = prev + cnt;
        }

        return s;
    }
};