class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i =0, j = 0, k = 0;
        string ans = "";
        bool isWord1 = true;
        while(i < word1.length() && j < word2.length()){
            char c;
            if (isWord1) {
                c =  word1[i];
                i++;
                isWord1 = false;
            } else {
                c =  word2[j];
                j++;
                isWord1 = true;
            }
            ans += c;
        }

        while(i < word1.length()) {
            ans += word1[i++];
        }

        while(j < word2.length()) {
            ans += word2[j++];
        }

        return ans;
    }
};