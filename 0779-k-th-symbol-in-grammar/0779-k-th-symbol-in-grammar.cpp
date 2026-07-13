class Solution {
public:
    int depthFirstSearch(int n, int k, int rootVal) {
        if (n == 1) {
            return rootVal;
        }

        int totalNodes = pow(2, n - 1);

        // Target node will be present in the right half sub-tree of the current
        // root node.
        if (k > (totalNodes / 2)) {
            int nextRootVal = (rootVal == 0) ? 1 : 0;
            return depthFirstSearch(n - 1, k - (totalNodes / 2), nextRootVal);
        }
        // Otherwise, the target node is in the left sub-tree of the current
        // root node.
        else {
            int nextRootVal = (rootVal == 0) ? 0 : 1;
            return depthFirstSearch(n - 1, k, nextRootVal);
        }
    }

    int kthGrammar(int n, int k) { return depthFirstSearch(n, k, 0); }
};

// // TLE
// class Solution {
// public:
//     int kthGrammar(int n, int k) {
//         string s = "0";
//         vector<string> ans;
//         ans.push_back(s);
//         while (n >= 0) {
//             string last = ans.back();
//             string next = "";
//             for (char c : last) {
//                 if (c == '0') {
//                     next += "01";
//                 } else if (c == '1') {
//                     next += "10";
//                 }
//             }
//             ans.push_back(next);
//             n--;
//         }

//         string temp = ans.back();
//         return temp.at(k - 1) - '0';
//     }
// };