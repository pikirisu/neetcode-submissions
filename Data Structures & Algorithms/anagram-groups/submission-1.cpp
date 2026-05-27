class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string,vector<string>> mapper;
        for(string s : strs){

            vector<int> freq(26,0);

            for(char c:s){
                freq[c-'a']++;
            }

            string key = "";

            for(int count:freq){
                key+=to_string(count)+"#";
            }

            mapper[key].push_back(s);
        }

        for(auto it:mapper){
            ans.push_back(it.second);
        }

        return ans;
    }
};
