class Solution {
public:
    long long sumAndMultiply(int n) {
        int sum = 0, ans = 1;
        string num = "";
        bool isZero = false;
        string o = to_string(n);

        for (char c : o) {
            if (c == '0') {
                continue;
            } else {
                isZero = true;
                num += c;
                sum += c - '0';
            }
        }

        if (!isZero) {
            return 0;
        }

        return sum * stol(num);
    }
};