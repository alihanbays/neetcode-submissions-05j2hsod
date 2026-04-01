class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) {
            return "";
        }

        unordered_map<char, int> windowFreq;
        unordered_map<char, int> subStringFreq;

        for (char& ch : t) {
            subStringFreq[ch]++;
        }

        int l = 0;
        int matches = 0;
        pair<int ,int> index;
        int resLen = INT_MAX;
        for (int r = 0; r < s.length(); r++) {
            windowFreq[s[r]]++;
            auto it = subStringFreq.find(s[r]);
            if (it != subStringFreq.end() && subStringFreq[s[r]] == windowFreq[s[r]]) {
                matches++;
            } 

            while (matches == subStringFreq.size()) {
                if (r - l + 1 < resLen) {
                    resLen = r - l + 1 ;
                    index = {l, r};
                }
                windowFreq[s[l]]--;
                auto it = subStringFreq.find(s[l]);
                if (it != subStringFreq.end() &&  windowFreq[s[l]] < subStringFreq[s[l]]) {
                    matches--;
                }
                l++;
            }
        }
        
        if (resLen == INT_MAX) {
            return "";
        } else {
            return s.substr(index.first, resLen);
        }
    }
};
