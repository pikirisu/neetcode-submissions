class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            int complement = target - numbers[i];
            if(mp.find(complement)!= mp.end())
            return {mp[complement]+1,i+1};
            else mp[numbers[i]]=i;
        }
        return {};
    }
};
