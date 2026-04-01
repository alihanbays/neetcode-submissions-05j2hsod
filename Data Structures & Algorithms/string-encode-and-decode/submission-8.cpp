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
        vector<string> result;
        int i = 0;
        while (i < s.length()) {
            int delim_index = s.find('#', i);
            int word_size = stoi(s.substr(i, delim_index - i));
            cout << to_string(word_size) << endl;
            result.push_back(s.substr(delim_index + 1, word_size));
            i = word_size + delim_index + 1; 
        } 
        return result;
    }
};
