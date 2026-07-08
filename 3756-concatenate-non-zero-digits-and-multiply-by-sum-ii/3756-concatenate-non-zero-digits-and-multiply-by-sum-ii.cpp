class Solution {
public:
    static const int MOD = 1e9 + 7;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();

        vector<long long> prefVal(n + 1, 0);
        vector<long long> prefSum(n + 1, 0);
        vector<int> prefCnt(n + 1, 0);
        vector<long long> pow10(n + 1, 1);

        for (int i = 1; i <= n; i++) {
            pow10[i] = (pow10[i - 1] * 10) % MOD;
        }

        for (int i = 0; i < n; i++) {
            int digit = s[i] - '0';

            prefVal[i + 1] = prefVal[i];
            prefSum[i + 1] = prefSum[i];
            prefCnt[i + 1] = prefCnt[i];

            if (digit != 0) {
                prefVal[i + 1] = (prefVal[i] * 10 + digit) % MOD;
                prefSum[i + 1] = prefSum[i] + digit;
                prefCnt[i + 1] = prefCnt[i] + 1;
            }
        }

        vector<int> ans;

        for (auto& q : queries) {
            int l = q[0];
            int r = q[1];

            long long sum = prefSum[r + 1] - prefSum[l];

            int cnt = prefCnt[r + 1] - prefCnt[l];

            long long x =
                (prefVal[r + 1] - (prefVal[l] * pow10[cnt]) % MOD + MOD) % MOD;

            ans.push_back((x * sum) % MOD);
        }

        return ans;
    }
};