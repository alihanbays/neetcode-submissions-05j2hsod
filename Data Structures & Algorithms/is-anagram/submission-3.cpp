class Solution {
public:
    bool isAnagram(string s, string t) {

        if (s.length() != t.length()) {
            return false;
        }

        unordered_map<char, int> checkAnagramS;
        unordered_map<char, int> checkAnagramT;

        for (int i = 0; i < s.length(); i++) {
            if (checkAnagramS.count(s[i])) {
                checkAnagramS.at(s[i]) += 1;
            } else {
                checkAnagramS.insert({s[i], 1});
            }

            if (checkAnagramT.count(t[i])) {
                checkAnagramT.at(t[i]) += 1;
            } else {
                checkAnagramT.insert({t[i], 1});
            }
        }

        if (checkAnagramS != checkAnagramT) {
            return false;
        }

        return true;
    }
};
