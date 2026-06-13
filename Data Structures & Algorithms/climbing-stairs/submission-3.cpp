class Solution {
public:
    void solve(int n,int& count){
        // Base Case
        if(n==0){
            count++;
            return;
        }

        if(n<=0)
        return;
        
        // 1 Step
        solve(n-1,count);

        // 2 Step
        solve(n-2,count);
    }

    int solveMemo(int n,vector<int>&dp){
        // Step 1 : Create DP array

        if(n==0){
            return 1;
        }

        if(n<=0)
        return 0;

        // Step 3 : Return any case where answer already exist
        if(dp[n]!=-1)
        return dp[n];
        
        // Step 2 : Store Answers from both cases
        // Answers from both cases
        dp[n] =  solveMemo(n-1,dp) +solveMemo(n-2,dp);
        return dp[n];
    }
    int climbStairs(int n) {
        // solve(n,count);
        vector<int>dp(n+1,-1);
        return solveMemo(n,dp);
    }
};
