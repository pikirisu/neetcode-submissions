class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==1) return 1;
        unordered_set<int>st(nums.begin(),nums.end());

        int maxm = 0;

        int n = nums.size();

        for(int i=0; i<n; i++){
            if(st.find(nums[i]-1)==st.end()){
                int curr = nums[i];
                int len = 1;
                while(st.find(curr+1)!=st.end()){
                    curr++;
                    len++;
                }
                maxm = max(len,maxm);
            }
        }

        return maxm;
    }
};
