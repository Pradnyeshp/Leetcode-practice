class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> adj(n + 1);
        vector<int> inDegree(n + 1, 0);
        vector<int> maxTime(n + 1, 0);

        // Build adjacency list and in-degree counts
        for (int i = 0; i < relations.size(); ++i) {
            int u = relations[i][0];
            int v = relations[i][1];
            adj[u].push_back(v);
            inDegree[v]++;
        }

        queue<int> q;

        // Push courses with no prerequisites into the queue
        for (int i = 1; i <= n; ++i) {
            maxTime[i] = time[i - 1];
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        // Process courses using Kahn's Algorithm
        while (!q.empty()) {
            int u = q.front();
            int size = adj[u].size();
            q.pop();

            for (int i = 0; i < size; ++i) {
                int v = adj[u][i];
                maxTime[v] = max(maxTime[v], maxTime[u] + time[v - 1]);
                inDegree[v]--;

                if (inDegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        // Find maximum completion time across all courses
        int result = 0;
        for (int i = 1; i <= n; ++i) {
            result = max(result, maxTime[i]);
        }

        return result;
    }
};