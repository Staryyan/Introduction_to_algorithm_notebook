#include <iostream>
#include <vector>
using namespace std;
vector<int> computePrefix(string pattern) {
    int len = (int)pattern.size();
    vector<int> prefix(len, 0);
    prefix[0] = -1;
    int k = -1;
    for (int i = 1; i < pattern.size(); ++i) {
        while (k > -1 && pattern[k + 1] != pattern[i]) {
            k = prefix[k];
        }
        if (pattern[k + 1] == pattern[i]) {
            k++;
        }
        prefix[i] = k;
    }
    return prefix;
}

int KMP(string str, string pattern) {
    vector<int> prefix = computePrefix(pattern);
    int k = -1;
    int target = pattern.size();
    for (int i = 0; i < str.size(); ++i) {
        while (k > -1 && pattern[k + 1] != str[i]) {
            k = prefix[k];
        }
        if (pattern[k + 1] == str[i]) {
            k++;
        }
        if (k == target - 1) {
            return i - pattern.size() + 1;
        }
    }
    return -1;
}
int main() {
    string str = "yanzexin";
    string pattern = "yanx";
    cout << KMP(str, pattern) << endl;
}