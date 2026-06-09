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
    // Max Heap custom Comparator
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
        // First k elements window
        for(int i=0;i<k;i++){
            Info  temp = Info(nums[i],i);
            pq.push(temp);
        }
        // Push element for first window
        Info top = pq.top();
        ans.push_back(top.val);
        // For next windows
        for(int i=k;i<n;i++){
            // Check if top is out of window + lazy deletion here
            while(!pq.empty() && pq.top().index<i-k+1)
            pq.pop();
            // Push current one to priority queue
            pq.push({nums[i],i});
            // Push answer for current window
            ans.push_back(pq.top().val);
        }
        return ans;
    }
};