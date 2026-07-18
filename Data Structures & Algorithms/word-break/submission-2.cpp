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
    bool solveTab(string& s, vector<string>& wordDict){
        int n = s.length();
        vector<bool>dp(n+1,false);

        dp[n] = true;

        for (int i = n - 1; i >= 0; i--){
            for(auto word : wordDict){
                int len = word.length();
                if(s.substr(i,len)==word && dp[i+len]==true)
                dp[i]=true;
                
            }
        }
        return dp[0];
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        // int n = s.length();
        // vector<int>dp(n+1,-1);
        // return solveMem(s,wordDict,0,dp);
        return solveTab(s,wordDict);
    }
};
