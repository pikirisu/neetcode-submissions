class Solution {
public:
    int mini = INT_MAX;
    int solve(vector<int>& coins, int amount){
        // Base Case
        if(amount<0)
        return -1;

        if(amount == 0)
        return 0;

        int min_coins = INT_MAX;

        for(auto coin : coins){
            int res = solve(coins,amount-coin);

            if(res!=-1){
                if(res<INT_MAX){
                    min_coins = min(min_coins,res+1);
                }
            }
        }
        return min_coins;
    }

    int solveMem(vector<int>& coins, int amount, vector<int>&dp){
        // Base Case
        if(amount<0)
        return -1;

        if(amount == 0)
        return 0;

        if(dp[amount]!=-1)
        return dp[amount];

        dp[amount] = INT_MAX;

        for(auto coin : coins){
            int res = solveMem(coins,amount-coin,dp);

            if(res!=-1){
                if(res<INT_MAX){
                    dp[amount] = min(dp[amount],res+1);
                }
            }
        }
        return dp[amount];
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1,-1);
        int res = solveMem(coins,amount,dp);
        return (res==INT_MAX) ? -1 : res;
    }
};
