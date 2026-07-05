class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;

        for (int stone : stones) {
            pq.push(stone);
        }

        while (pq.size() > 1) {
            int top1 = pq.top();
            pq.pop();
            int top2 = pq.top();
            pq.pop();
            int diff = abs(top1 - top2);
            if (diff > 0) {
                pq.push(diff);
            }
        }

        if (pq.empty()) {
            return 0;
        }

        return pq.top();
    }
};