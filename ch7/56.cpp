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
private:
    int partition(vector<Interval>& vec, int left, int right) {
        Interval x = vec[right];
        int i = left - 1;
        for (int j = left; j < right; ++j) {
            if (vec[j].start < x.start) {
                i++;
                swap(vec[i], vec[j]);
            }
        }
        swap(vec[i + 1], vec[right]);
        return i + 1;
    }
    void quickSort(vector<Interval>& vec, int left, int right) {
        if (left < right) {
            int mid = partition(vec, left, right);
            quickSort(vec, left, mid - 1);
            quickSort(vec, mid + 1, right);
        }
    }
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        if (intervals.empty()) { return vector<Interval>{}; }
        quickSort(intervals, 0, (int)intervals.size() - 1);
        Interval Int = intervals[0];
        vector<Interval> ans;
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
