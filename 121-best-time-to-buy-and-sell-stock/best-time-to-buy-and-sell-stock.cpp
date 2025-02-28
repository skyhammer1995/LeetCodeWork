class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int minBuy = prices[0];

        for (const auto& price : prices) {
            if (price < minBuy) {
                minBuy = price;
            } else if ((price - minBuy) > maxProfit) {
                maxProfit = price - minBuy;
            }
        }

        return maxProfit;
    }
};