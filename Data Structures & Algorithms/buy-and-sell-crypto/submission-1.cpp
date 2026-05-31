class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int min_p = prices[0];
        int max_p = 0;
        for(int price : prices){
            max_p = max(max_p,price-min_p);
            min_p = min(min_p,price);
        }
        return max_p;
    }
};
