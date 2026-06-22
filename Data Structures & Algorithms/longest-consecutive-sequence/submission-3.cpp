class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        vector<int>maxm(n,1);
        
        for(int i=0; i<n; i++){
            int search = nums[i]+1;
            for(int j=0;j<n;j++){
                if(search==nums[j]){
                    maxm[i]++;
                    search++;
                    j=-1;
                }
            }
        }
        sort(maxm.begin(), maxm.end(), greater<int>());

        return maxm[0];
    }
};
