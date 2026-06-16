class Solution {
public:
    string processStr(string s) {
        string res = "";

        for (char c: s) {
            if (islower(c) != 0){
                res += c;
            }
            if (c == '*') {
                if (!res.empty()) {
                    res.pop_back();
                }
            }
            if(c == '#'){
                res += res;
            } 
            if(c == '%'){
                reverse(res.begin(), res.end());
            } 
        }

        return res;
    }
};