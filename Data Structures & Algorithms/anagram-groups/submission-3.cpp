class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string,vector<string>> mapper;
        for(auto &str : strs){
            string cpy = str; 
            sort(cpy.begin(),cpy.end());
            mapper[cpy].push_back(str);
        }

        for(auto &it : mapper){
            ans.push_back(it.second);
        }

        return ans;
    }
};
