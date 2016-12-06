/**
 * TLE
 */
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    bool check(vector<pair<int, int>> resPeople, int size, pair<int, int> waitingPeople) {
        if (waitingPeople.second > size) {
            return false;
        } else {
            int count = 0;
            for (int i = 0; i < size; ++i) {
                if (resPeople[i].first >= waitingPeople.first) {
                    count++;
                }
            }
            return count == waitingPeople.second;
        }
    }
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        vector<pair<int, int>> resPeople(people.size(), pair<int, int>(0, 0));
        int len = people.size();
        for (int i = 0; i < len; ++i) {
            pair<int, int> bestChoice(INT_MAX, 0);
            for (int j = 0; j < len; ++j) {
                if (check(resPeople, i, people[j])) {
                    if (bestChoice.first > people[j].first) {
                        bestChoice = people[j];
                    }
                }
            }
            resPeople[i] = bestChoice;
        }
        return resPeople;
    }
};
int main() {
    vector<pair<int, int>> res{{7,0},{4,4},{7,1},{5,0},{6,1},{5,2}};
    Solution().reconstructQueue(res);
}

/**
 * Succeed.
 */
class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        auto comp = [](const pair<int, int> p1, const pair<int, int> p2) {
            return p1.first > p2.first || (p1.first == p2.first && p1.second < p2.second);
        };
        sort(people.begin(), people.end(), comp);
        vector<pair<int, int>> resPeople;
        for (auto each : people) {
            resPeople.insert(resPeople.begin() + each.second, each);
        }
        return resPeople;
    }
};
