class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, vector<int>> mp;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }
        for(int i = 0; i < n; i++) {
            int complement = target - nums[i];

            if(mp.find(complement) != mp.end()) {
                if(complement == nums[i]) {

                    if(mp[nums[i]].size() >= 2) {
                        return {mp[nums[i]][0], mp[nums[i]][1]};
                    }
                    continue;
                }
                return {i, mp[complement][0]};
            }
        }
        return {-1, -1};
    }
};