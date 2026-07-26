class StockPrice {
    int latestTime;
    // Store price of each stock at each timestamp.
    unordered_map<int, int> timestampPriceMap;
    // Store stock prices in increasing order to get min and max price.
    map<int, int> priceFrequency;

public:
    StockPrice() { latestTime = 0; }

    void update(int timestamp, int price) {
        // Update latestTime to latest timestamp.
        latestTime = max(latestTime, timestamp);

        // If same timestamp occurs again, previous price was wrong.
        if (timestampPriceMap.find(timestamp) != timestampPriceMap.end()) {
            // Remove previous price.
            int oldPrice = timestampPriceMap[timestamp];
            priceFrequency[oldPrice]--;

            // Remove the entry from the map.
            if (priceFrequency[oldPrice] == 0) {
                priceFrequency.erase(oldPrice);
            }
        }

        // Add latest price for timestamp.
        timestampPriceMap[timestamp] = price;
        priceFrequency[price]++;
    }

    int current() {
        // Return latest price of the stock.
        return timestampPriceMap[latestTime];
    }

    int maximum() {
        // Return the maximum price stored at the end of sorted-map.
        return priceFrequency.rbegin()->first;
    }

    int minimum() {
        // Return the maximum price stored at the front of sorted-map.
        return priceFrequency.begin()->first;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */