class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> us;
        int l = 0;
        int res = 0;

        for (int r = 0; r < s.length(); r++) {
            while (us.find(s[r]) != us.end()) {
                us.erase(s[l]);
                l++;
            }
            us.insert(s[r]);
            res = max(res, (int)us.size());
        }
        return res;
    }
};
