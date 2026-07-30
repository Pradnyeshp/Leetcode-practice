class Solution {
public:
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        vector<long long> ans;
        unordered_map<int, long long> idToFreqMap;
        priority_queue<pair<long long, int>> maxHeap;

        for (int i = 0; i < nums.size(); ++i) {
            // push the item to map and update the total freq
            idToFreqMap[nums[i]] += freq[i];
            // push the <freq, id> to the max heap
            maxHeap.push({idToFreqMap[nums[i]], nums[i]});

            while (maxHeap.size() &&
                   idToFreqMap[maxHeap.top().second] != maxHeap.top().first) {
                // Now if the top element's freq is different
                // from the freq in the map then its a stale
                // entry and remove it from the heap. Keep doing
                // this untill we have a top item that have
                // matching freq as per map
                maxHeap.pop();
            }

            // push the heap top item's freq in to the answer
            ans.push_back(maxHeap.top().first);
        }
        return ans;
    }
};