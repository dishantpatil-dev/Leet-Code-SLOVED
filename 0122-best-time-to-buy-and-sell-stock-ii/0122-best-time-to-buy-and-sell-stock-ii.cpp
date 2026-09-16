class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy=prices[0],sum=0;
        for(int i=1;i<prices.size();i++)
        {
            if(buy<prices[i])
            {
                sum+=prices[i]-buy;
                buy=prices[i];

            }
            else{buy=prices[i];}
        }
        return sum;
        
    }
};