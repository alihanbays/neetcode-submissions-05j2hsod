class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.length() - 1;

        while (l < r) {
            while (l < r && !alphaNum(s[l])) {
                l++;
            }
            while (r > l && !alphaNum(s[r])) {
                r--;
            }

            if (std::tolower(s[l]) != std::tolower(s[r])) {
                std::cout << s[l] << " " << s[r] << std::endl;
                return false;
            }

            l++;
            r--;
        }
        return true;
    }

    bool alphaNum(char c) {
        if (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z' || c >= '0' && c <= '9') {
            return true;
        }
        return false;
    }
};
