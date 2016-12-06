#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> inDegree(numCourses, 0);
        vector<vector<int>> son(numCourses);
        for (int i = 0; i < prerequisites.size(); ++i) {
            inDegree[prerequisites[i].first]++;
            son[prerequisites[i].second].push_back(prerequisites[i].first);
        }
        queue<int> courseQueue;
        int finishedCourse = 0;
        for (int j = 0; j < numCourses; ++j) {
            if (inDegree[j] == 0) { courseQueue.push(j); finishedCourse++; }
        }
        while (!courseQueue.empty()) {
            int top = courseQueue.front();
            courseQueue.pop();
            for (int i = 0; i < son[top].size(); ++i) {
                inDegree[son[top][i]]--;
                if (inDegree[son[top][i]] == 0) {
                    finishedCourse++;
                    courseQueue.push(son[top][i]);
                }
            }
        }
        return finishedCourse == numCourses;
    }
};
