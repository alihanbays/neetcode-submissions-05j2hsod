class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> us;

        for (int i = 0; i < nums.size(); i++) {
            us.insert(nums[i]);
        }

        int max_length = 0;
        for (auto it = us.begin(); it != us.end(); ++it) {
            int val = *it;
            int length = 0;
            if (us.find(val-1) == us.end()) {
                length++;
                while (us.find(val + 1) != us.end()) {
                    length++;
                    val++;
                }

                max_length = max(max_length, length);
            }
        }

        return max_length;
    }
};
