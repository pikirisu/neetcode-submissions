class Solution {
public:
    // class Greater{
    //     bool operator()(pair<int,int> a, pair<int,int> b){
    //         return a.first>b.first;
    //     }
    // }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        unordered_map<int,int> mp;

        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }

        vector<vector<int>> bucket(n + 1);

        for(auto p : mp){
            bucket[p.second].push_back(p.first);
        }

        for(int i = n; i>=0 && ans.size()<k; i--){
            for(int num : bucket[i]){
                ans.push_back(num);
                if(ans.size()==k)
                break;
            }
        }

        return ans;
    }
};
