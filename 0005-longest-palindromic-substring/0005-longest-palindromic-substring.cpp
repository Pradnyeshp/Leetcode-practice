class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) {
            return ""; // Edge case: empty string has no palindrome
        }

        int start = 0,
            end =
                0; // Will hold start and end indices of the longest palindrome

        // Loop through each character in the string
        for (int i = 0; i < s.length(); i++) {
            // Check for odd-length palindrome centered at s[i]
            int odd = expandAroundCenter(s, i, i);

            // Check for even-length palindrome centered between s[i] and s[i+1]
            int even = expandAroundCenter(s, i, i + 1);

            // Take the longer length
            int max_len = max(odd, even);

            // Update start and end if this palindrome is longer than the
            // previous longest
            if (max_len > end - start) {
                // Compute the new start and end based on the center and length
                start = i - (max_len - 1) / 2;
                end = i + max_len / 2;
            }
        }

        // Return the longest palindromic substring
        return s.substr(start, end - start + 1);
    }

private:
    // Helper function to expand the palindrome around the center
    int expandAroundCenter(string s, int left, int right) {
        // Expand as long as the characters match and indices are in bounds
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }

        // Return the length of the palindrome found
        return right - left -
               1; // Subtract 1 because we've expanded one step too far
    }
};