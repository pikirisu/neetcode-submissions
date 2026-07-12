class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
      int maxm = 0;
        int count = 0;
        int n = nums.size();
      for(int i=0; i<n; i++){
        if(!(nums[i]==1)){
        count = 0;
        }
        else {
            count++;
            maxm = max(maxm,count);
        }
        
      }
      return maxm;
    }
};