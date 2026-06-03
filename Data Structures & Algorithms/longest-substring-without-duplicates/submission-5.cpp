class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> lastSeen;
        int l = 0;
        int ans = 0;

        for (int r = 0; r < s.size(); r++) {
            if (lastSeen.count(s[r]) && lastSeen[s[r]] >= l) {
                l = lastSeen[s[r]] + 1;
            }
            lastSeen[s[r]] = r;
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};