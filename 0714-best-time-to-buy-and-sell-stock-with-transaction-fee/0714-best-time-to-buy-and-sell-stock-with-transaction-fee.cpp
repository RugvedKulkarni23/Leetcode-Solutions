class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int sell=0,buy=-prices[0];
         if (prices.size() <= 1) return 0;
        for(int i=0;i<prices.size();i++){
            buy=max(buy,sell-prices[i]);
            sell=max(sell,prices[i]-fee+buy);
        }
        return sell;
    }
};