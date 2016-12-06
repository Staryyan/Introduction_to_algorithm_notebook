/**
 * https://leetcode.com/problems/gas-station/
 */
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = 0, subSum = INT_MAX;
        int start = 0;
        for (int i = 0; i < gas.size(); ++i) {
            totalGas += gas[i] - cost[i];
            if (totalGas < subSum) {
                subSum = totalGas;
                start = i + 1;
            }
        }
        return totalGas < 0 ? -1 : start % gas.size();
    }
};