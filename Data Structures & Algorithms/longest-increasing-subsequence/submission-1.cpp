class Solution {
   public:
    int solve(vector<int>& nums, int idx, int prevIdx) {
        // Base case
        if (idx == nums.size()) return 0;
        // Include
        int include = 0;

        if (prevIdx == -1 || nums[prevIdx]< nums[idx]) {
            include = 1+solve(nums, idx + 1, idx);
        }
        // Exclude
        int exclude = solve(nums, idx + 1, prevIdx);
        return max(include, exclude);
    }

    int solveMem(vector<int>& nums, int idx, int prevIdx,vector<vector<int>>&dp) {
        // Base case
        if (idx == nums.size()) return 0;
        int n = nums.size();

        if(dp[idx][prevIdx+1]!= -1)
        return dp[idx][prevIdx+1];

        // Include
        int include = 0;

        if (prevIdx == -1 || nums[prevIdx]< nums[idx]) {
            include = 1+solveMem(nums, idx + 1, idx,dp);
        }
        // Exclude
        int exclude = solveMem(nums, idx + 1, prevIdx,dp);

        dp[idx][prevIdx+1] = max(include, exclude);

        return dp[idx][prevIdx+1];
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solveMem(nums, 0, -1,dp);
    }
};
