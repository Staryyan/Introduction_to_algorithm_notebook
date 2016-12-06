/**
 * TLE
 */
class Solution {
private:
    bool transform(int len, string beginWord, string endWord) {
        int count = 0;
        for (int i = 0; i < len; ++i) {
            if (beginWord[i] != endWord[i]) { count++; }
        }
        return count == 1;
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
        vector<vector<string>> ans;
        int len = beginWord.size();
        if (transform(len, beginWord, endWord)) { return vector<vector<string>>{{beginWord, endWord}}; }
        if (beginWord == endWord)  //corner case;
        {
            ans.push_back(vector<string>{beginWord});
            return ans;
        }
        queue<vector<string>> ladderQueue;
        ladderQueue.push(vector<string>{beginWord});
        bool finished = false;
        while (!finished && !ladderQueue.empty()) {
            int size = ladderQueue.size();
            for (int i = 0; i < size; ++i) {
                auto vec = ladderQueue.front();
                ladderQueue.pop();
                string lastOne = vec[vec.size() - 1];
                if (transform(len, lastOne, endWord)) {
                    vec.push_back(endWord);
                    ans.push_back(vec);
                    finished = true;
                    continue;
                }
                for (auto word : wordList) {
                    if (transform(len, lastOne, word)) {
                        vector<string> next = vec;
                        next.push_back(word);
                        ladderQueue.push(next);
                    }
                }
            }
        }
        return ans;
    }
};
