class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map <int,int> mp;
        int n = nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        int times = k;
        while(times--){
            int most_freq = 0;
            int most_freq_val = 0;
            for(auto var :  mp){
                if(var.second>most_freq){
                    most_freq = var.second;
                    most_freq_val = var.first;
                }
            }
            ans.push_back(most_freq_val);
            mp[most_freq_val] = 0;
        }

        return ans;
        
    }
};
