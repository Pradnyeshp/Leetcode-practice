class Solution {
public:
    char processStr(string s, long long k) {
        int n = s.length();
        vector<long long> lengths(n + 1, 0);

        for (int i = 0; i < n; i++) {
            char ch = s[i];
            long long length = lengths[i];
            if (islower(ch)) {
                lengths[i + 1] = length + 1;
            } else if (ch == '*') {
                lengths[i + 1] = max(0LL, length - 1);
            } else if (ch == '#') {
                lengths[i + 1] = length * 2;
            } else if (ch == '%') {
                lengths[i + 1] = length;
            }
        }

        long long finalLength = lengths[n];

        if (k < 0 || k >= finalLength) {
            return '.';
        }

        for (int i = n - 1; i >= 0; i--) {
            char ch = s[i];
            long long beforeLen = lengths[i];
            long long afterLen = lengths[i + 1];

            if (islower(ch)) {
                if (k == afterLen - 1) {
                    return ch;
                }
            } else if (ch == '*') {
                continue;
            } else if (ch == '#') {
                if (k >= beforeLen) {
                    k -= beforeLen;
                }
            } else if (ch == '%') {
                k = beforeLen - 1 - k;
            }
        }

        return '.';
    }
};