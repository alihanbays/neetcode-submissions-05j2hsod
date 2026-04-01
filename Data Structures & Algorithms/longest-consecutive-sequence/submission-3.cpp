class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // Little cheat we could do is sort but
        if (nums.size() == 0) {
            return 0;
        }

        sort(nums.begin(), nums.end());
        int length = 1;
        int max = 1;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] + 1 < nums[i+1]) {
                cout << to_string(nums[i] + 1) << " < " << to_string(nums[i+1]) << endl;
                // sequence bitti, bakalim en buyuk mu
                if (length > max) {
                    max = length;
                }
                length = 1;
            } else if (nums[i] + 1 == nums[i+1]) {
                length++;
            }

            if (length > max) {
                max = length;
            }
        }
        return max;
    }
};
