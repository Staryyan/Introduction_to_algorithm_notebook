/**
 * https://leetcode.com/problems/non-overlapping-intervals/
 */
class Solution {
public:
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        auto comp = [](const Interval int1, const Interval int2) {
            return int1.start < int2.start || (int1.start == int2.start && int1.end < int2.end);
        };
        sort(intervals.begin(), intervals.end(), comp);
        int res = 0;
        for (int i = 0; i < intervals.size(); ++i) {
            int j = i + 1;
            while (j < intervals.size() && intervals[i].end > intervals[j].start) {
                intervals[i].end = min(intervals[i].end, intervals[j].end);
                j++;
            }
            res++;
            i = j - 1;
        }
        return intervals.size() - res;
    }
};