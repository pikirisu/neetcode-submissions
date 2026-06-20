class Solution {
public:
    int solve(int n){
        if(n<0) return 0;
        if(n==0) return 0;
        if(n==1) return 1;
        if(n==2) return 1;

        int ans = solve(n-1) + solve(n-2) + solve(n-3);
        return ans;
    }

    int solveMem(int n,vector<int>&dp){
        if(n<0) return 0;
        if(n==0) return 0;
        if(n==1) return 1;
        if(n==2) return 1;

        if(dp[n]!=-1)
        return dp[n];

        dp[n] = solveMem(n-1,dp) + solveMem(n-2,dp) + solveMem(n-3,dp);
        return dp[n];
    }

    int solveTab(int n){
        vector<int> dp(n+5,0);

        dp[1] = 1;
        dp[2] = 1;

        for(int i=3; i<=n; i++){
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
        }

        return dp[n];
    }

    int solveTabSpace(int n){

        int prev1 = 0;
        int prev2 = 1;
        int prev3 = 1;

        if(n==0) return prev1;
        if(n==1) return prev2;
        if(n==2) return prev3;

        for(int i=3; i<=n; i++){
            int ans  = prev3 + prev2 + prev1;

            // Shifting
            prev1 = prev2;
            prev2 = prev3;
            prev3 = ans;
        }

        return prev3;
    }

    int tribonacci(int n) {
        // vector<int>dp(n+1,-1);
        // return solveMem(n,dp);

        return solveTabSpace(n);   
    }
};