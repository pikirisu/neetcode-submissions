class Solution {
public:
    vector<vector<int>> ans;
    void solve(int start,vector<int>& nums, vector<int>& curr){
        ans.push_back(curr);
    for(int i=start;i<nums.size();i++){
        // include nums[i]
        curr.push_back(nums[i]);
        solve(i+1, nums, curr);
        // exclude nums[i]
        curr.pop_back();
    }

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        
        int i = 0;
        vector<int> curr;
        solve(i,nums,curr);
        return ans;
    }
};
