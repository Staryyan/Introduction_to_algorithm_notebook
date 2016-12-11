/**
 * hash table.
 */
class Solution {
public:
    int hIndex(vector<int>& citations) {
        if (citations.size() == 0) { return 0; }
        int n = (int)citations.size();
        vector<int> hash(n + 1, 0);
        for (auto each : citations) {
            if (each >= n) {
                hash[n]++;
            } else {
                hash[each]++;
            }
        }
        int ans = 0;
        for (int i = n; i >= 0; --i) {
            ans += hash[i];
            if (ans >= i) {
                return i;
            }
        }
        return 0;
    }
};

int main() {
    vector<int> vec{0};
    cout << Solution().hIndex(vec) << endl;
    return 0;
}
