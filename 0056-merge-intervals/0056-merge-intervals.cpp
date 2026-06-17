class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // rusty old solution 
        // std::sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b) {
        //     return a[0] < b[0];
        // } );

        // vector<vector<int>> ans;

        // for(int i = 0; i < intervals.size() - 2; i++){ 
        //     int last = intervals[i][1];
        //     int next = intervals[i+1][0];
        //     cout << "comparing last " << last << " with next " << next << endl;
        //     vector<int> val;
        //     if(last >= next){
        //         val[0] = intervals[i][0];
        //         val[1] = intervals[i+1][1];
        //     } else {
        //         val[0] = intervals[i][0];
        //         val[1] = intervals[i][1];
        //     }
        //     ans.push_back(val);
        // }

        // return ans;

        // Sort intervals based on start time
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged;
        vector<int> prev = intervals[0];

        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= prev[1]) {
                // Merge overlapping intervals
                prev[1] = max(prev[1], intervals[i][1]);
            } else {
                merged.push_back(prev);
                prev = intervals[i];
            }
        }

        merged.push_back(prev);
        return merged;
    }
};