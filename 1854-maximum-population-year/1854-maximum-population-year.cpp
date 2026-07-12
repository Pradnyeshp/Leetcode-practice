class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {

        int n = logs.size();
        vector<int> birth(n), death(n);

        for (int i = 0; i < n; i++) {
            birth[i] = logs[i][0];
            death[i] = logs[i][1];
        }

        sort(birth.begin(), birth.end());
        sort(death.begin(), death.end());

        int i = 0, j = 0;
        int population = 0;
        int maxPop = 0;
        int year = birth[0];

        while (i < n) {
            if (birth[i] < death[j]) {
                population++;
                if (population > maxPop) {
                    maxPop = population;
                    year = birth[i];
                }
                i++;
            } else {
                population--;
                j++;
            }
        }

        return year;
    }
};

// line sweep O(n)
// class Solution {
// public:
//     int maximumPopulation(vector<vector<int>>& logs) {

//         int pop[101] = {0};

//         for(auto &log : logs){
//             pop[log[0] - 1950]++;
//             pop[log[1] - 1950]--;
//         }

//         int maxPop = 0;
//         int year = 1950;
//         int curr = 0;

//         for(int i = 0; i < 101; i++){
//             curr += pop[i];

//             if(curr > maxPop){
//                 maxPop = curr;
//                 year = 1950 + i;
//             }
//         }

//         return year;
//     }
// };