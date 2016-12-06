/**
 * 135
 */
#include <vector>
using namespace std;
class Solution {
public:
    int candy(vector<int>& ratings) {
        int min = INT_MAX;
        vector<int> candiesScan1(ratings.size(), 0);
        vector<int> candiesScan2(ratings.size(), 0);
        candiesScan1[0] = 1;
        for (int i = 1; i < ratings.size(); ++i) {
            candiesScan1[i] = ratings[i] > ratings[i - 1] ? candiesScan1[i - 1] + 1 : 1;
        }
        candiesScan2[ratings.size() - 1] = 1;
        for (int j = ratings.size() - 2; j >= 0; --j) {
            candiesScan2[j] = ratings[j] > ratings[j + 1] ? candiesScan2[j + 1] + 1 : 1;
        }
        int sum = 0;
        for (int k = 0; k < ratings.size(); ++k) {
            sum += max(candiesScan1[k], candiesScan2[k]);
        }
        return sum;
    }
};