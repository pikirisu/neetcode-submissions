class Solution {
public:
    bool isPalindrome(string& s,int l, int r){
        while(l<r){
            if(s[l]!=s[r])
            return false;

            l++;
            r--;
        }

        return true;
    }
    
    void solveMem(string&s, int l, int r,string &maxm, vector<vector<int>>&dp){
        // Base case
        if(l>r)
        return;

        if(dp[l][r]!=-1)
        return;

        dp[l][r] = 1;

        if(isPalindrome(s,l,r)){
            if(r-l+1 > maxm.length()){
                maxm = s.substr(l,r-l+1);
                return;
            }
        }
        else{
            solveMem(s,l+1,r,maxm,dp);
            solveMem(s,l,r-1,maxm,dp);
        }
    }

    string longestPalindrome(string s) {
        int r = s.length()-1;
        string maxm = "";
        vector<vector<int>> dp(r+1,vector<int>(r+1,-1));
        solveMem(s,0,r,maxm,dp);
        return maxm;   
    }
};
