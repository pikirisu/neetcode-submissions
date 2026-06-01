class Solution {
public:
    int findDuplicate(vector<int>& nums) {
      unordered_map<int,int> freq;
      int n = nums.size();
      for(int i=0;i<n;i++){
        freq[nums[i]]++;
      }

      for(int i=0;i<n;i++){
        if(freq[nums[i]]>1)
        return nums[i];
      }

      return -1;
    }
};
