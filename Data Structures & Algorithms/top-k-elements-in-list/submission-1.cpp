class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        unordered_map<int,int> mp;

        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }

        priority_queue<pair<int,int>> pq;

        for(auto val : mp){
            pq.push({val.second,val.first});
        }

        for(int i=0;i<k;i++){
            pair<int,int> element = pq.top();
            ans.push_back(element.second);
            pq.pop();
        }

        return ans;
        
    }
};
