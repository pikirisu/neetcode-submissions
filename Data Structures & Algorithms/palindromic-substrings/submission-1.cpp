class Solution {
public:
    bool isPalindrome(string&s,int l, int r){
        while(l<r){
            if(s[l]!=s[r])
            return false;

            l++;
            r--;
        }

        return true;
    }
    int countSubstrings(string s) {
        int n = s.length();
        int count = 0;

        for(int i=0; i<n;i++){
            for(int j=1;j<=n-i;j++){
                if(isPalindrome(s,i,i+j-1))
                count++;
            }
        }

        return count;
    }
};
