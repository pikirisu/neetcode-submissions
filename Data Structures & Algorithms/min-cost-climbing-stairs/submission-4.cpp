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

    int solveTab(vector<int>&cost){
        int n = cost.size();
        vector<int> dp(n+1,0);

        dp[n-1] = cost[n-1];
        dp[n-2] = cost[n-2];

        for(int i=n-3; i>=0; i--){
            dp[i] = cost[i] + min(dp[i+1],dp[i+2]);
        }
        return min(dp[0],dp[1]);
    }

    int solveTabSpace(vector<int>&cost){
        int n = cost.size();
        int next1 = cost[n-2];
        int next2 = cost[n-1];

        int curr = 0;
        for(int i=n-3; i>=0; i--){
            curr = cost[i] + min(next1,next2);

            next2 = next1;
            next1 = curr;
        }
        return min(next2,next1);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        // vector<int> dp(n+1,-1);

        // return min(solveMem(cost,0,dp),solveMem(cost,1,dp));

        return solveTabSpace(cost);
    }
};
