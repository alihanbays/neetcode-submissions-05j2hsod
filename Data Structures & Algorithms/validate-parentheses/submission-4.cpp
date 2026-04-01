class Solution {
public:
    bool isValid(string s) {
        std::unordered_map<char,char> m = { {'{','}'}, {'(',')'},{ '[',']'} };
        stack<char> st;

        for (auto c : s) {
            if (!m.count(c) && st.size() >= 1 && st.top() == c) {
                st.pop();
            } else if (m.count(c)) {
                st.push(m.at(c));
            } else {
                return false;
            }
        }

        return st.size() == 0;
    }
};
