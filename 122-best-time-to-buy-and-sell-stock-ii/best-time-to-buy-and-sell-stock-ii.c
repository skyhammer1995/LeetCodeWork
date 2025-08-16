int maxProfit(int* prices, int pricesSize) {
    int totalProfit = 0;
    int currentMaxProfit = 0;    
    int minBuy = prices[0];

    for (int i = 0; i < pricesSize; i++) {
        if (prices[i] < minBuy) {
            minBuy = prices[i];
        } else if ((prices[i] - minBuy) > currentMaxProfit) {
            currentMaxProfit = prices[i] - minBuy;
            // sell immediately, since we can just buy today, and "step up" profit
            totalProfit += currentMaxProfit;
            currentMaxProfit = 0;
            minBuy = prices[i];
        }
    }

    return totalProfit;
}