class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        int max_p = 0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                max_p = max(max_p,prices[j]-prices[i]);
            }
        }
        return max_p;
    }
};
