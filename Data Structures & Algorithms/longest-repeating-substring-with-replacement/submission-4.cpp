class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        int max_length = 0;
        unordered_map<char, int> freq;
        int maxFreq = 0;

        for (int r = 0; r < s.length(); r++) {
            freq[s[r]]++;
            maxFreq = max(freq[s[r]], maxFreq);
            if (maxFreq + k >= (r - l + 1)) {
                max_length = max(max_length, r - l + 1);
            }

            while (maxFreq + k < (r - l + 1)) {
                freq[s[l]]--;
                l++;
            }
        }
        return max_length;
    }
};
