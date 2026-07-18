class Solution {
public:
    bool solve(string& s, vector<string>& wordDict, int i){
        if(i==s.length()) return true;

        for(auto word : wordDict){
            if(s.substr(i,word.length())==word){
                if(solve(s,wordDict,i+word.length()))
                return true;
            }
        }
        return false;
    }
    bool solveMem(string& s, vector<string>& wordDict, int i,vector<int>&dp){
        if(i==s.length()) return true;

        if(dp[i]!=-1)
        return dp[i];

        for(auto word : wordDict){
            if(s.substr(i,word.length())==word){
               if (solveMem(s,wordDict,i+word.length(),dp)) {
                dp[i] = 1;
                return true;
            }
            }
        }
        dp[i] = 0;
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        vector<int>dp(n+1,-1);
        return solveMem(s,wordDict,0,dp);
    }
};
