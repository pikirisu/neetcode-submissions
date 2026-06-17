class Solution {
public:
    int solve(vector<int>& nums,int index){
        // Base Case
        if(index>=nums.size())
        return 0;

        int include =  nums[index]+solve(nums,index+2);

        int exclude = 0 + solve(nums,index+1);

        return max(include,exclude);
    }

    int solveMem(vector<int>& nums,int index,vector<int>&dp){
        // Base Case
        int n = nums.size();
        if(index>=n)
        return 0;

        if(dp[index]!=-1)
        return dp[index];

        int include =  nums[index]+solveMem(nums,index+2,dp);

        int exclude = 0 + solveMem(nums,index+1,dp);
        dp[index] =  max(include,exclude);
        return dp[index];
    }

    int solveTab(vector<int>& nums){
        // Base Case
        int n = nums.size();
        vector<int> dp(n+2,0);
        for(int index=n-1; index>=0; index--){
            
            int include =  nums[index]+dp[index+2];

            int exclude = 0 + dp[index+1];

            dp[index] =  max(include,exclude);
        }

        return max(dp[0],dp[1]);
    }

    int rob(vector<int>& nums) {
        // return solve(nums,0);
        int n = nums.size();
        // vector<int> dp(n+1,-1);
        // return solveMem(nums,0,dp);
        return solveTab(nums);
    }
};
