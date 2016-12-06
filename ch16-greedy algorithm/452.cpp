/**
 * https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/
 */
#include <vector>
using namespace std;
class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
        auto comp = [](const pair<int, int> p1, const pair<int, int> p2) {
            return p1.first < p2.first || (p1.first == p2.first && p1.second < p2.second);
        };
        sort(points.begin(), points.end(), comp);
        int res = 0;
        for (int i = 0; i < points.size(); ++i) {
            int j = i + 1;
            while (j < points.size() && points[i].second >= points[j].first) {
                points[i].second = min(points[i].second, points[j].second);
                j++;
            }
            res++;
            i = j - 1;
        }
        return res;
    }
};
