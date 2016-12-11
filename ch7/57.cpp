/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> ans;
        if (intervals.empty()) { ans.push_back(newInterval); return ans; }
        bool inserted = false;
        for (vector<Interval>::iterator iter = intervals.begin(); iter != intervals.end(); iter++) {
            if (iter->start > newInterval.start) {
                inserted = true;
                iter = (iter == intervals.begin()) ? intervals.begin() : iter;
                intervals.insert(iter, newInterval);
                break;
            }
        }
        if (!inserted) { intervals.push_back(newInterval); }
        for (auto each : intervals) {
            cout << each.start << " "  << each.end << endl;
        }
        Interval Int = intervals[0];
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i].start <= Int.end) {
                Int.end = max(Int.end, intervals[i].end);
            } else {
                ans.push_back(Int);
                Int = intervals[i];
            }
        }
        ans.push_back(Int);
        return ans;
    }
};