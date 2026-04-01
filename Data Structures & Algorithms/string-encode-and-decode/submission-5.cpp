class Solution {
public:

    string encode(vector<string>& strs) {
        string result { "" };

        for (const string& str : strs) {
            result += to_string(str.length()) + '#' + str;
        }

        return result;
    }

    vector<string> decode(string s) {
        string size {""};
        vector<string> result;
        
        int i = 0;
        int j = 0;
        while (i < s.length()) {
            // Find # index and get size while at it!
            while (s[j] != '#') {
                size += s[j];
                j++;
            }

            // now size is 5 and j is pointing at #
            // get the first word: hello
            string sub = s.substr(j+1, stoi(size));
            cout << sub << endl;
            result.push_back(sub);

            i += sub.length() + size.length() + 1;
            size = "";
            j = i;
        }

        return result;
    }
};
