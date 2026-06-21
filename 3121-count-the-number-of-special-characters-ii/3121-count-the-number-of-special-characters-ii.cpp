class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> lastLower(26, -1);   // last index seen in lowercase
        vector<int> firstUpper(26, -1);  // first index seen in uppercase

        for (int i = 0; i < (int)word.size(); i++) {
            char c = word[i];
            if (islower(c)) {
                lastLower[c - 'a'] = i;
            } else if (firstUpper[c - 'A'] == -1) {
                firstUpper[c - 'A'] = i;
            }
        }

        int res = 0;
        for (int i = 0; i < 26; i++) {
            if (lastLower[i] != -1 && firstUpper[i] != -1 && lastLower[i] < firstUpper[i]) {
                res++;
            }
        }
        return res;
    }
};