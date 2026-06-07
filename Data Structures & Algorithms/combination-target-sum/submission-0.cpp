class Solution {
public:
    vector<vector<int>> ans;
    void solve(int i, vector<int>& nums, vector<int>path,int target){
        if(target == 0){
        ans.push_back(path);
        return;
    }

    if(i == nums.size() || target < 0)
        return;

    // take
    path.push_back(nums[i]);
    solve(i, nums, path, target - nums[i]);
    path.pop_back();
    // skip
    solve(i + 1, nums, path, target);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        int i=0;
        vector<int> path;
        solve(i,nums,path,target);
        return ans;
    }
};
