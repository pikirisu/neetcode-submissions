class Solution {
public:
    int lengthOfLastWord(string s) {
        int r = s.length()-1;
        if(r==0) return 1;

        while(s[r]==' ')
        r--;
        int x = 0;
        while(s[r--]!=' ')
        x++;

        return x;
    }
};