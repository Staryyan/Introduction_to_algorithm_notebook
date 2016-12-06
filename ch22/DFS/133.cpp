/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;
struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};
class Solution {
private:
    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> hash;
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node) { return node; }
        if (hash.find(node) == hash.end()) {
            hash[node] = new UndirectedGraphNode(node->label);
            for (auto each : node->neighbors) {
                hash[node]->neighbors.push_back(cloneGraph(each));
            }
        }
        return hash[node];
    }
};