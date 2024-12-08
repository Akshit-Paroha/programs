class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int buy= prices[0];
        int n = prices.size();
        int maxprofit=0;
        for(int i=0;i<n;i++)
        {
            if(prices[i]<buy)
            {
                buy = prices[i];
            }
            else
            {
                maxprofit=max(maxprofit,prices[i]-buy);
            }
        }    
        return maxprofit;    
    }
};