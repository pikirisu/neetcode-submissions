class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        int maxm = 0;
        for(int i=0; i<n; i++){
            int prod = 1;
            for(int j=i;j<n; j++){
                prod*=nums[j];
                maxm = max(prod,maxm);
            }
        }

        return maxm;
    }
};
