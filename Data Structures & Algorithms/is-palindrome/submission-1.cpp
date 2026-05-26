class Solution {
public:
    string clean(string s){
        string ans ="";
        for(int i=0;i<s.length();i++){
            char ch = s[i];
            if(s[i]>64 && s[i]<91){
            ch = ch-'A'+'a';
            ans.push_back(ch);
            }
            else if (s[i]>96 && s[i]<123)
            ans.push_back(ch);
            else if(s[i] >= '0' && s[i] <= '9')
            ans.push_back(ch);
            else continue;
        }
        return ans;
    }
    bool isPalindrome(string s) {
        string cleaned = clean(s);
        int l = 0;
        int e = cleaned.length()-1;

        while(l<e){
            if(cleaned[l]!=cleaned[e])
            return false;
            
            l++;
            e--;
        }
        return true;
    }
};
