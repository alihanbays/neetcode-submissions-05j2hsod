class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;

        res.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) {
            // First comparison 
            // 1->2, 1->4
            // Check if they are clashing
            if (res.back()[1] > intervals[i][0]) {
                // Decide which one to remove
                if (res.back()[1] > intervals[i][1]) {
                    res.pop_back();
                    res.push_back(intervals[i]);
                }
            } else {
                res.push_back(intervals[i]);
            }
        }
        return intervals.size() - res.size();
    }
};
