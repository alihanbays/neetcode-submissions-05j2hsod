class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> us;

        int l = 0;
        int r = 0;
        int max_length = 0;
        while (r < s.length()) {
            if (us.find(s[r]) == us.end()) { // char is not in the set
                us.insert(s[r]);
                max_length = max(max_length, (int)us.size());
                r++;
            } else {
                // pop until we are unique;
                while (us.find(s[r]) != us.end()) {
                    us.erase(s[l]);
                    l++;
                }
            }
        }

        return max_length;
    }
};
