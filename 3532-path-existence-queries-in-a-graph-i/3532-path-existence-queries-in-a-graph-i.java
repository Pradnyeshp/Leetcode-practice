class Solution {
    public boolean[] pathExistenceQueries(int n, int[] nums, int maxDiff, int[][] queries) {
        int[] component = new int[n];
        int compId = 0;

        // Step 1: Assign components
        for (int i = 1; i < n; i++) {
            if (nums[i] - nums[i - 1] <= maxDiff) {
                component[i] = compId; // Same component as the previous node
            } else {
                compId++; // New component
                component[i] = compId;
            }
        }

        // Step 2: Answer queries
        boolean[] answer = new boolean[queries.length];
        for (int i = 0; i < queries.length; i++) {
            int u = queries[i][0];
            int v = queries[i][1];
            answer[i] = component[u] == component[v]; // Check if both nodes belong to the same component
        }

        return answer;
    }
}