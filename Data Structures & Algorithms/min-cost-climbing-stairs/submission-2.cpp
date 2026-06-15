class Solution {
public:
    int solve(vector<int>& cost, int index){
        // Base Case
        if(index >= cost.size())
            return 0;

        return cost[index] + min(solve(cost, index + 1), solve(cost, index + 2));

    }
    // 1D DP
    int solveMem(vector<int>& cost, int index, vector<int>& dp){
        // Base Case
        if(index >= cost.size())
            return 0;

        if(dp[index]!=-1)
        return dp[index];

        dp[index] =  cost[index] + min(solveMem(cost, index + 1,dp), solveMem(cost, index + 2,dp));
        return dp[index];

    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1,-1);
        return min(solveMem(cost,0,dp),solveMem(cost,1,dp));
    }
};
