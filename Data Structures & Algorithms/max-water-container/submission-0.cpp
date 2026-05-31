class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int max_w = INT_MIN;

        int h = 0;
        int w = 0;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int width = j - i;
                h = min(heights[i],heights[j]);
                max_w = max(max_w,h*width);
            }
        }
        return max_w;
    }
};
