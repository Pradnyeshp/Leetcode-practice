class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        stack<int> st;
        int n = heights.size();
        vector<int> a(n);

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && st.top() < heights[i]) {
                st.pop();
                a[i]++;
            }
            if (!st.empty()) {
                a[i]++;
            }
            st.push(heights[i]);
        }

        return a;
    }
};