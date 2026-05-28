class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> pq;
        int n = nums.size();

        for(int i=0;i<k;i++){
            cout<<"Pushing: "<<nums[i];
            pq.push(nums[i]);
            cout<<endl;
        }

        for(int i=k;i<n;i++){
            if(nums[i]>pq.top()){
                cout<<"Popping: "<<pq.top();
                pq.pop();
                cout<<endl;
                cout<<"Pushing: "<<nums[i];
                pq.push(nums[i]);
                cout<<endl;
            }
        }
        cout<<"Returning: "<<pq.top();
        return pq.top();
    }
};
