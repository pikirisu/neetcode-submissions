class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>pq;
        int n = nums.size();
        for(int i=0;i<n;i++){
            cout<<"Pushing: "<<nums[i];
            pq.push(nums[i]);
            cout<<endl;
        }

        for(int i=0;i<k-1;i++){
            cout<<"Popping: "<<pq.top();
            pq.pop();
            cout<<endl;
        }
        cout<<"Returning: "<<pq.top();
        return pq.top();
    }
};
