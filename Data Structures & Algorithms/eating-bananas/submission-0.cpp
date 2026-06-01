class Solution {
public:
    bool helper(vector<int>& piles, int mid, int h){
        int curr = 0;
        int n = piles.size();
        for(int i=0;i<n;i++){
            curr+=((piles[i]+mid-1)/mid);
        }
        return (curr<=h);
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();

        int mini = INT_MAX;
        int maxi = INT_MIN;

        for(int i=0;i<n;i++){
            mini = min(mini,piles[i]);
            maxi = max(maxi,piles[i]);
        }

        int l = 1;
        int r = maxi;
        int ans = INT_MAX;
        while(l<=r){
            int mid = l+(r-l)/2;
            cout << "mid = " << mid << " helper = " << helper(piles, mid, h)<< endl;
            if(helper(piles,mid,h)){
                ans = mid;
                r=mid-1;
            }
            else l = mid+1;
        }
        return ans;
    }
};
