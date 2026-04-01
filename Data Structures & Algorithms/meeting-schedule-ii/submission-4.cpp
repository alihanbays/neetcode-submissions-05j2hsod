/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */
struct CompareIntervals {
    bool operator()(const Interval& a, const Interval& b) {
        return a.end > b.end;
    }
};

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        if (intervals.size() < 1) {
            return 0;
        }
        // If they are not clashing time they can share room, if not wen eed to ad a room
        sort(intervals.begin(), intervals.end(), [](Interval& a, Interval& b) {
            return a.start < b.start;
        });

        int requiredRoom = 1;
        priority_queue<Interval, vector<Interval>, CompareIntervals> roomque;
        roomque.push(intervals[0]);

        for (int i = 1; i < intervals.size(); i++) {
            if (roomque.top().end > intervals[i].start) { // Clashing
                roomque.push(intervals[i]);
            } else {
                Interval tmp = roomque.top();
                tmp.end = intervals[i].end;
                roomque.pop();
                roomque.push(tmp);
            }
        }
        

        return roomque.size();
    }
};
