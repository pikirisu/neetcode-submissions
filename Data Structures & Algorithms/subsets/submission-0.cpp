class Solution {
public:
    void solve(int i,vector<int> nums, vector<int> curr,vector<vector<int>>& ans){
    if(i==nums.size()){
        ans.push_back(curr);
        return;
    }
    // include nums[i]
    curr.push_back(nums[i]);
    solve(i + 1, nums, curr, ans);

    // exclude nums[i]
    curr.pop_back();
    solve(i + 1, nums, curr, ans);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int i = 0;
        vector<int> curr;
        solve(i,nums,curr,ans);
        return ans;
    }
};
