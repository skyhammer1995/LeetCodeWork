class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int totalProfit = 0;
        int currentMaxProfit = 0;
        int minBuy = prices[0];

        for (const auto& price : prices) {
            if (price < minBuy) {
                minBuy = price;
            } else if ((price - minBuy) > currentMaxProfit) {
                currentMaxProfit = price - minBuy;
                // sell immediately, since we can just buy today, and "step up" profit
                totalProfit += currentMaxProfit;
                currentMaxProfit = 0;
                minBuy = price;
            } 
        }
        return totalProfit;
    }
};