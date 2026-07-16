class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i=0;
        int j=i+1;
        int profit=0;
        while(i <prices.size() && j < prices.size()){
            if(prices[i] > prices[j]){
                i=j;
                j++;
                continue;
            }
            int prof = prices[j] - prices[i];
            profit = max(profit,prof);
            j++;
        }
        return profit;
    }
};