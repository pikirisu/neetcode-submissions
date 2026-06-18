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

    int solveTab(vector<int>&nums){

        int n = nums.size();

        if(n==1) return nums[0];
        vector<int> dp1(n+2,0);
        vector<int> dp2(n+2,0);

        for(int i=n-2; i>=0; i--){
            int include = nums[i] + dp1[i+2];
            int exclude = 0 + dp1[i+1];

            dp1[i] = max(include,exclude);
        }

        for(int i=n-1; i>0; i--){
            int include = nums[i] + dp2[i+2];
            int exclude = 0 + dp2[i+1];

            dp2[i] = max(include,exclude);
        }

        return max(dp1[0],dp2[1]);
    }

    int solveTabSpace(vector<int>&nums){

        int n = nums.size();

        if(n==1) return nums[0];
        int next1 = 0;
        int next2 = 0;

        for(int i=n-2; i>=0; i--){
            int ans  =  0;
            int include = nums[i] + next2;
            int exclude = 0 + next1;

            ans = max(include,exclude);

            next2 = next1;
            next1 = ans;

        }

        int next11 = 0;
        int next22 = 0;

        for(int i=n-1; i>0; i--){
            int ans = 0;
            int include = nums[i] + next22;
            int exclude = 0 + next11;

            ans = max(include,exclude);

            next22 = next11;
            next11 =  ans;
        }

        return max(next1,next11);
    }

    int rob(vector<int>& nums) {
        // int e = nums.size()-1;
        // vector<int> dp1(e+1,-1);
        // vector<int> dp2(e+1,-1);
        // // Handling Circle Independently by making 2 cases for 1st house
        // int ans1 = solveMemo(nums,2,e-1,dp1)+nums[0]; // Excluding Last case as if 1st house picked
        // int ans2 = solveMemo(nums,1,e,dp2);           // Last Needs to be removed for 1st ans
        
        return solveTabSpace(nums);
    }
};
