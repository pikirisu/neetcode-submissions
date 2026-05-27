class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string,vector<string>> mapper;
        for(int i=0;i<strs.size();i++){
            string curr = strs[i];
            string store = strs[i];
            sort(curr.begin(),curr.end());
            mapper[curr].push_back(store);
        }

        for(auto it:mapper){
            ans.push_back(it.second);
        }

        return ans;
    }
};
