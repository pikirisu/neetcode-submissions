class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        string common = strs[0];
        for(int i=1; i<n; i++){
            string curr = strs[i];
            string new_common = "";
            for(int j=0;j<strs[i].size();j++){
                if(curr[j]==common[j]){
                    new_common+=common[j];
                }
                else{
                    break;
                }
            }
            common = new_common;
        }
        return common;

    }
};