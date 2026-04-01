class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) {
            return "";
        }

        unordered_map<int, int> count_map;
        unordered_map<int, int> window_map;

        for (char& ch : t) {
            count_map[ch]++;
        }

        int l = 0;
        int need = count_map.size();
        int have = 0;
        pair<int, int> indexes;
        int window_size = INT_MAX;
        for (int r = 0; r < s.length(); r++) {
            char& ch = s[r]; 
            window_map[ch]++;

            if (count_map.count(ch) && window_map[ch] == count_map[ch]) {
                have++;
            }

            while (have == need) {
                if (r - l + 1 < window_size) {
                    window_size = r - l + 1;
                    indexes.first = l;
                    indexes.second = r;
                }
                window_map[s[l]]--;
                if (count_map.count(s[l]) && window_map[s[l]] < count_map[s[l]]) {
                    have--;
                }
                l++;
            }
        }

        if (window_size == INT_MAX) {
            return "";
        }
        return s.substr(indexes.first, window_size);
    }
};
