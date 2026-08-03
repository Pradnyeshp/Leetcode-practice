class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> adj(numCourses);
        vector<int> order;

        for (auto i : prerequisites) {
            auto prereq = i[1];
            auto sub = i[0];
            adj[prereq].push_back(sub);
            indegree[sub]++;
        }

        queue<int> q;
        for (int i = 0; i < indegree.size(); i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int nxt = q.front();
            order.push_back(nxt);
            q.pop();

            for (auto n : adj[nxt]) {
                indegree[n]--;
                if (indegree[n] == 0) {
                    q.push(n);
                }
            }
        }

        if (order.size() == numCourses) {
            return order;
        } else {
            return {};
        }
    }
};