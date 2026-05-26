class Solution {
public:
    string clean(string s){
        string ans ="";

        for(char ch : s){
            if(isalnum(ch))
            ans.push_back(tolower(ch));
        }
        return ans;
    }
    bool isPalindrome(string s) {
        string cleaned = clean(s);

        int l = 0;
        int r = cleaned.length()-1;

        while(l<r){
            if(cleaned[l]!=cleaned[r])
            return false;
            l++;
            r--;
        }
        return true;
    }
};
