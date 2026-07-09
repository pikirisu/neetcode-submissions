class Solution {
public:
    int solve(string &s, int i){
        // Base Case
        if(i==s.length())
        return 1;

        if(s[i]=='0') return 0;

        int ans = solve(s,i+1);

        if (i + 1 < s.length()) {
            int num = (s[i] - '0') * 10 + (s[i + 1] - '0');
            if (num >= 10 && num <= 26)
                ans += solve(s, i + 2);
            }

        return ans;
    }

    int solveMem(string &s, int i,vector<int>&dp){
        // Base Case
        if(i==s.length())
        return 1;

        if(s[i]=='0') return 0;

        if(dp[i]!=-1)
        return dp[i];

        dp[i] = solveMem(s,i+1,dp);

        if (i + 1 < s.length()) {
            int num = (s[i] - '0') * 10 + (s[i + 1] - '0');
            if (num >= 10 && num <= 26)
                dp[i] += solveMem(s, i + 2,dp);
            }

        return dp[i];
    }

    int numDecodings(string s) {
        // int ans = solve(s,0);
        // return ans;
        int n = s.length();
        vector<int>dp(n,-1);
        int ans = solveMem(s,0,dp);
        return ans;
    }
};
