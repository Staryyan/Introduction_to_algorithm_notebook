#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <set>
using namespace std;
class Solution {
private:
    queue<pair<string, int>> nodeQueue;
    unordered_map<string, set<pair<string, int>>> hash;
    vector<vector<string>> answer;
    void DFS(set<pair<string, int>> st, vector<string> vec) {
        for (auto each : st) {
            vec.push_back(each.first);
            if (hash.count(each.first) == 0) {
                reverse(vec.begin(), vec.end());
                answer.push_back(vec);
                return;
            }
            DFS(hash[each.first], vec);
            vec.pop_back();
        }
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
        wordList.insert(endWord);
        wordList.erase(beginWord);
        nodeQueue.push({beginWord, 1});
        while (!nodeQueue.empty()) {
            auto tmp = nodeQueue.front();
            nodeQueue.pop();
            for (int i = 0; i < tmp.first.size(); ++i) {
                string _str = tmp.first;
                for (int j = 0; j < 26; ++j) {
                    _str[i] = 'a' + j;
                    if (wordList.count(_str)) {
                        nodeQueue.push({_str, tmp.second + 1});
                        wordList.erase(_str);
                        hash[_str].insert(tmp);
                    } else if (hash.count(_str) && hash[_str].begin()->second == tmp.second) {
                        hash[_str].insert(tmp);
                    }
                }
            }
        }
        DFS(hash[endWord], vector<string>{endWord});
        return answer;
    }
};