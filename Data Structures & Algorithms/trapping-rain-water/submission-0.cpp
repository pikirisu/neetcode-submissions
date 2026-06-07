class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int net_w = 0;
        vector<int>left_wall(n);
        left_wall[0]=height[0];

        for(int i=1; i<n; i++){
            left_wall[i]=max(left_wall[i-1],height[i]);
        }

        vector<int>right_wall(n);
        right_wall[n-1]=height[n-1];

        for(int i=n-2; i>=0; i--){
            right_wall[i]=max(right_wall[i+1],height[i]);
        }

        for(int i=0; i<n; i++){
            net_w += min(left_wall[i],right_wall[i]) - height[i];
        }

        return net_w;
        
    }
};
