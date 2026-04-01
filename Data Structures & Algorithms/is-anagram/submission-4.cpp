class Solution {
public:
    bool isAnagram(string s, string t) {

        if (s.length() != t.length()) {
            return false;
        }

        unordered_map<char, int> checkAnagramS;
        unordered_map<char, int> checkAnagramT;

        for (int i = 0; i < s.length(); i++) {
            checkAnagramS[s[i]]++;
            checkAnagramT[t[i]]++;
        }

        return checkAnagramS == checkAnagramT;
    }
};
