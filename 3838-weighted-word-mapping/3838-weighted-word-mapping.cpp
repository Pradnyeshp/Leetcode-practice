class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        // unordered_map<int, int> w;
        string res;

        for (string s: words){
            int sum = 0;
            for (char c: s){
                sum += weights[c - 'a'];
            }
            int mod = sum % 26;
            res += 'z' - (mod);
        }

        return res;
    }
};