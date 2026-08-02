class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> adj(numCourses);
        queue<int> q;
        for (auto i : prerequisites) {
            int prereq = i[1];
            int next = i[0];
            adj[prereq].push_back(next);
            indegree[next]++;
        }

        for (int i = 0; i < indegree.size(); i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int nxt = q.front();
            q.pop();
            for (auto nei : adj[nxt]) {
                indegree[nei]--;
                if (indegree[nei] == 0) {
                    q.push(nei);
                }
            }
        }

        for (auto i : indegree) {
            if (i != 0) {
                return false;
            }
        }
        return true;
    }
};