class Solution {
public:
    int maxProfit(vector<int>& prices) {

      // Start by setting min price to first day price 
      // this helps track lowest price i can buy so far. 
        int minPrice = prices[0];

    // start with 0 profit becuase i haven't made any transaction yet
        int maxProfit = 0;

      // loop through all days starting from second day 
        for (int i = 1; i < prices.size(); i++) {
            
            // if todays price is higher than min price it. means selling today could make a profit so i will check if this profit is greater than current maxProfit
            if (prices[i] > minPrice) {
                maxProfit = max(maxProfit, prices[i] - minPrice);
            }
            // i will always update minPrice if we find a smaller price so this will ensure that i am always buying at lowest price. 
           
            minPrice = min(minPrice, prices[i]);
        }

// after checking all days, maxprofit will hold the maximum profit.
        return maxProfit;
    }
};