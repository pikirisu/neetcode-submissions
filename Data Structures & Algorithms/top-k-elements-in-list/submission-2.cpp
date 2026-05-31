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

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int, int>>> pq;

        for(auto val : mp){
            pq.push({val.second,val.first});
            if(pq.size()>k)
            pq.pop();
        }

        for(int i=0;i<k;i++){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
        
    }
};
