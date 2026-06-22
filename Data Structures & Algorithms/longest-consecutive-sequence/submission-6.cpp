class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        if(n==1) return 1;

        unordered_set<int> st;

        for(int i=0; i<n; i++){
            st.insert(nums[i]);
        }

        int maxm = 1;

        for(auto it : st){
            if(st.find(it-1)==st.end()){
                int len = 1;
                int curr = it;

                while(st.find(curr+1)!=st.end()){
                    len++;
                    curr++;
                }

                maxm = max(maxm,len);
            }
        }

        return maxm;
    }
};
