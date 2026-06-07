class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0;
        int r = n-1;
        int mid = (l + r)/2;
        while(l<=r){
            if(nums[mid]==target) return mid;
            else if(nums[mid]>target) r=mid-1;
            else l=mid+1;

            mid = (l+r)/2;
        }
        return l;

    }
};