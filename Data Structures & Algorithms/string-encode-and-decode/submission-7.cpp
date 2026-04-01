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
        cout << s << endl;
        while (i < s.length()) {
            // Find the delimater #
            int delimIndex = s.find('#', i);
            // extract size
            int size = stoi(s.substr(i, i + delimIndex));
            //extract the word
            result.push_back(s.substr(delimIndex + 1, size));

            i += size + delimIndex - i + 1;
            cout << to_string(size) << " " << to_string(delimIndex) << endl;
            
        } 
        return result;
    }
};
