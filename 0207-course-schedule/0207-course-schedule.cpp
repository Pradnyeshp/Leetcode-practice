class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> adj(numCourses);

        for (auto i : prerequisites) {
            int prereq = i[1];
            int next = i[0];
            adj[prereq].push_back(next);
            indegree[next]++;
        }

        queue<int> q;
        vector<int> order;
        for (int i = 0; i < indegree.size(); i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int nxt = q.front();
            order.push_back(nxt);
            q.pop();
            for (auto nei : adj[nxt]) {
                indegree[nei]--;
                if (indegree[nei] == 0) {
                    q.push(nei);
                }
            }
        }

        return order.size() == numCourses;
    }
};