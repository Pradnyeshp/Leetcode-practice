class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.length();
        // Create a difference array initialized to 0
        vector<int> diff(n + 1, 0);

        for (const auto& shift : shifts) {
            int start = shift[0];
            int end = shift[1];
            int val = (shift[2] == 1) ? 1 : -1;

            diff[start] += val;
            diff[end + 1] -= val;
        }

        int currentShift = 0;
        for (int i = 0; i < n; i++) {
            currentShift += diff[i];
            // Calculate the net positive shift within the 26-letter alphabet
            // (Adding 26 handles negative net shifts correctly)
            int netShift = (currentShift % 26 + 26) % 26;
            // Apply the shift to the character
            s[i] = 'a' + (s[i] - 'a' + netShift) % 26;
        }

        return s;
    }
};