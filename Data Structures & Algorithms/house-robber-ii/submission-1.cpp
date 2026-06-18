class Solution {
public:
    int solve(vector<int>& nums, int s, int e){
        // Base Case
        if(s>e) return 0;

        int include = nums[s] + solve(nums,s+2,e);
        int exclude = 0 + solve(nums,s+1,e);

        int ans = max(include,exclude);
        return ans;

    }

    int solveMemo(vector<int>& nums, int s, int e,vector<int>&dp){
        // Base Case
        if(s>e) return 0;

        if(dp[s]!=-1)
        return dp[s];

        int include = nums[s] + solveMemo(nums,s+2,e,dp);
        int exclude = 0 + solveMemo(nums,s+1,e,dp);

        dp[s] = max(include,exclude);
        return dp[s];

    }
    int rob(vector<int>& nums) {
        int e = nums.size()-1;
        vector<int> dp1(e+1,-1);
        vector<int> dp2(e+1,-1);
        // Handling Circle Independently by making 2 cases for 1st house
        int ans1 = solveMemo(nums,2,e-1,dp1)+nums[0]; // Excluding Last case as if 1st house picked
        int ans2 = solveMemo(nums,1,e,dp2);           // Last Needs to be removed for 1st ans
        

        return max(ans1,ans2);
    }
};
