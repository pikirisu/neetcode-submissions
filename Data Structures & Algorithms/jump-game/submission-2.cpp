class Solution {
public:
    bool solve(vector<int>& nums, int idx){
        if(idx>= nums.size()-1)
        return true;

        for(int jump = 1; jump<=nums[idx]; jump++){
            if(solve(nums,idx + jump))
            return true;
        }

        return false;
    }
    bool canJump(vector<int>& nums) {
        return solve(nums,0);
    }
};
