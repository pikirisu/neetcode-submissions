class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;

        unordered_map<string, vector<string>> mapper;

        for (auto& str : strs) {
            vector<int> freq(26, 0);

            string original = str;

            string key = "";

            for (char c : str) {
                freq[c - 'a']++;
            }

            for (int num : freq) {
                key += to_string(num) + "#";
            }

            mapper[key].push_back(original);
        }
        for (auto it : mapper) {
            ans.push_back(it.second);
        }
        return ans;
    }
};
