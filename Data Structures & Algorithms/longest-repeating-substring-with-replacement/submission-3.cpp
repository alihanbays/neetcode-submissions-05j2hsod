class Solution {
public:
    bool isValidWindow(string s, int l, int r, int k) {
        unordered_map<char, int> freq;
        int maxFreq = 0;

        for (int i = l; i <= r; i++) {
            freq[s[i]]++;
            maxFreq = max(freq[s[i]], maxFreq);
        }

        if (maxFreq + k >= (r - l + 1)) {
            return true;
        }
        return false;
    }

    int characterReplacement(string s, int k) {
        int l = 0;
        int max_length = 0;

        for (int r = 0; r < s.length(); r++) {
            if (isValidWindow(s, l, r, k)) {
                max_length = max(max_length, r - l + 1);
            } else {
                l++;
            }
        }
        return max_length;
    }
};
