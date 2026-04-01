class Solution {
public:
    bool areAllUniqueChars(string s, int l, int r) {
        unordered_set<char> us;
        for (int i = l; i <= r; i++) {
            auto it = us.find(s[i]);

            if (it == us.end()) {
                us.insert(s[i]);
            } else {
                return false;
            }
        }
        return true;
    }

    int lengthOfLongestSubstring(string s) {
        int maxLength = 0;
        int l = 0;
        int r = 0;

        while (r < s.length()) {
            cout << "Sending: [" << s[l] << ", " << s[r] << "]" << endl;
            if (areAllUniqueChars(s, l, r)) {
                maxLength = max(maxLength, r - l + 1);
            } else {
                l++;
                r = l;
            }
            r++;
        }
        return maxLength;
    }
};
