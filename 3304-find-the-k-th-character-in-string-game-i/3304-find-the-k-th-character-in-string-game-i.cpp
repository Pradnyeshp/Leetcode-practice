class Solution {
public:
    char kthCharacter(int k) {
        string start = "a";

        // Keep simulating until we have enough characters
        while (start.size() < k) {
            start = start + nextString(start);
        }

        // k is 1-indexed, so we access k - 1
        return start[k - 1];
    }

    string nextString(string s) {
        string next = "";
        // Using standard index-based loop per your preference
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (c == 'z') {
                next += 'a';
            } else {
                next += c + 1;
            }
        }
        return next;
    }
};