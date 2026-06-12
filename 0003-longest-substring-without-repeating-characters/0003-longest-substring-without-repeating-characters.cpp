class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // create a vector of size 256 and all values are initialized
        // to -1 means this character has not been seen yet . and it
        // will store last index  of each character in the string .
        vector<int> map(256, -1);
        int left = 0, right = 0; // left and right are two pointers used to
                                 // define the sliding window of current substr
        int n = s.size();
        int len = 0;        // stores length of the string
        while (right < n) { // loop through string using right pointer
            // if current character s[right] was seen before and it is
            // still inside the current window(left, right) then
            if (map[s[right]] != -1) {
                // i will move left pointer to one position
                // after the last index of that character
                left = max(map[s[right]] + 1, left);
            }

            // updater the last seen index of s[right] to
            // the current psotion right
            map[s[right]] = right;
            // update length if current substring (r - l
            // + 1) is longer than the previous
            len = max(len, right - left + 1);
            // move to next character in the string
            right++;
        }
        return len;
    }
};
