class Solution {
public:

    string encode(vector<string>& strs) {
        string result = "";

        for (string str : strs) {
            int size = str.length();
            if (size == 0) {
                result += "0";
            } else if (size < 9) {
                result += "1" + to_string(str.length()) + str;
            } else if (size < 99) {
                result += "2" + to_string(str.length()) + str;
            } else {
                result += "3" + to_string(str.length()) + str;
            }
        }
        
        return result;
    }

    vector<string> decode(string s) {
        vector<string> result;
        cout << s << endl;
        string word = "";
        int size = 0;

        for (int i = 0; i < s.length(); i++) {
            if (size == 0) {
                int sizeOfInt = s[i] - '0'; // 0, 1, or 2
                cout << to_string(sizeOfInt) << endl;
                if (sizeOfInt == 0) {
                    result.push_back("");
                } else if (sizeOfInt == 1) {
                    size = s[i+1] - '0';
                    i += 1;
                } else if (sizeOfInt == 2) {
                    size = ((s[i+1] - '0') * 10) + s[i+2] - '0';
                    i += 2;
                } else if (sizeOfInt == 3) {
                    size = ((s[i+1] - '0') * 100) + ((s[i+2] - '0') * 10) + s[i+3] - '0';
                    i += 3;
                }
                cout << to_string(size) << endl;
            } else {
                word += s[i];
                size--;
                if (size == 0) {
                    result.push_back(word);
                    word = "";
                }
            }
        }
        return result;
    }
};
