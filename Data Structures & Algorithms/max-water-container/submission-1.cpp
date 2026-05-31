class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int l = 0;
        int r = n-1;

        long long max_w = 0;
        long long width = 0;
        long long height = 0;

        while(l<r){
            // Calculation for max water
            width = r-l;
            height = min(heights[l],heights[r]);
            max_w = max(max_w,height*width);

            // Bottleneck
            if(heights[l]<heights[r]) l++;
            else r--;
        }

        return max_w;
    }
};
