class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        if(nums.size()==1) return 1;
        sort(nums.begin(),nums.end());

        int maxm = 1;
        int curr = 1;

        for(int i=1; i<nums.size();i++){
            if(nums[i]==nums[i-1]+1){
                curr++;
            }
            else if(nums[i]==nums[i-1]){
                continue;
            }
            else{
                curr=1;
            }
            maxm=max(curr,maxm);
        }

        return maxm;
    }
};
