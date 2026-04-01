class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
    
        if (nums.size() == 0) {
            return 0;
        }

        unordered_set<int> us;
        for (int i = 0; i < nums.size(); i++) {
            us.insert(nums[i]);
        }

        int length = 0;
        int max = 0;
        for (const int& num : nums) {
            auto it = us.find(num-1);
            if (it == us.end()) {
                length++;
                int val = num;
                it = us.find(val + 1);
                while (it != us.end()) {
                    length++;
                    if (length >= max) {
                        max = length;
                    }
                    val = *it + 1;
                    it = us.find(val);
                }

                if (length >= max) {
                    max = length;
                }
                length = 0;
            }
        }

        return max;
    }
};
