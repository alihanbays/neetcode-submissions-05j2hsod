class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0;
        int r = heights.size() - 1;

        int max_height = 0;
        while (l < r) {
            int size = (r - l) * min(heights[l], heights[r]);
            if (size > max_height) {
                max_height = max(max_height, size);
            }

            if (heights[l] > heights[r]) {
                r--;
            } else {
                l++;
            }
        }

        return max_height;
    }
};
