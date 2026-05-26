class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> s;
        int n = nums.size();

        for(int i=0;i<n;i++){
            unordered_set<int> hashset;
            for(int j=i+1;j<n;j++){
                int third = -(nums[i]+nums[j]);
                if(hashset.find(third)!=hashset.end()){
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(third);

                        sort(temp.begin(),temp.end());
                        s.insert(temp);
                }
                else{
                    hashset.insert(nums[j]);
                }
            }
        }
        vector<vector<int>> ans (s.begin(),s.end());

        return ans;
    }
};
