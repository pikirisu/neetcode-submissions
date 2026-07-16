class Solution {
public:
    void solve(vector<int>& nums,vector<int>&path,vector<vector<int>>& ans, int i, int req){
        if(req==0){
            ans.push_back(path);
            return;
        }
        
        if(req<0)
        return;

        if(i==nums.size())
        return;

        // Include
        if(req>=nums[i]){
            path.push_back(nums[i]);
            solve(nums,path,ans,i,req-nums[i]);
            path.pop_back();
        }
        // Exclude
        solve(nums,path,ans,i+1,req);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int>path;

        solve(nums,path,ans,0,target);
        return ans;
    }
};
