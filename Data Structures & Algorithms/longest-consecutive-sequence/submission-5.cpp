class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        if(n==1) return 1;

        unordered_map<int,int>freq;

        for(int i=0; i<n; i++){
            freq[nums[i]]++;
        }

        int maxm = 1;

        for(int i=0; i<n; i++){
            if(freq.find(nums[i]-1)==freq.end()){
                int len = 1;
                int curr = nums[i];

                while(freq.find(curr+1)!=freq.end()){
                    len++;
                    curr++;
                }

                maxm = max(maxm,len);
            }
        }

        return maxm;
    }
};
