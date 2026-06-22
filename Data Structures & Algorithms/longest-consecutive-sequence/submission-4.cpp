class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;

        sort(nums.begin(),nums.end());
        int maxm = 1;
        int curr = 1;

        for(int i=0;i<n-1;i++){
            if(nums[i+1]==nums[i]+1){ // i.e. consecutive
                curr++;
                maxm=max(maxm,curr);

            }
            else if(nums[i]==nums[i+1]){
                continue;
            }
            else {
                maxm = max(maxm,curr);

                curr = 1;
            }
        }

        return maxm;
    }
};
