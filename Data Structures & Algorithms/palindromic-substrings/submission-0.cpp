class Solution {
public:
    bool isPalindrome(string s){
        int l = 0;
        int r = s.length()-1;

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
                string str = s.substr(i,j);
                if(isPalindrome(str))
                count++;
            }
        }

        return count;
    }
};
