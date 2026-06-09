class Solution {
public:
    class Info{
        public :
        int val;
        int index;

        Info(int val,int index){
            this->val=val;
            this->index = index;
        }
    };

    class comparator{
        public:
        bool operator()(Info a, Info b){
            return a.val < b.val;
        }
    };
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<Info,vector<Info>,comparator>  pq;
        vector<int>ans;
        int n = nums.size();

        for(int i=0;i<k;i++){
            Info  temp = Info(nums[i],i);
            pq.push(temp);
        }
        Info top = pq.top();
        ans.push_back(top.val);

        for(int i=k;i<n;i++){
            while(!pq.empty() && pq.top().index<i-k+1)
            pq.pop();
            
            pq.push({nums[i],i});
            ans.push_back(pq.top().val);
        }
        return ans;
    }
};