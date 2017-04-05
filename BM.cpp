#include <iostream>
#include <vector>
using namespace std;

#define MaxCharSize  256

vector<int> badCharVec;
vector<int> goodSuffixVec;
vector<int> suffix;


void computebadCharVec(string pattern) {
    int len = (int)pattern.length();
    /**
     * If the char hasn't existed in pattern,
     * just skip that char and shift pattern.length() steps.
     */
    badCharVec = vector<int>(MaxCharSize, len);
    /**
     * Don't stay or go back.
     */
    for (int i = 0; i < len - 1; ++i) {
        badCharVec[pattern[i]] = len - i - 1;
    }
}

void computeSuffix(string pattern) {
    int len = (int)pattern.length();
    suffix = vector<int>(len, 0);
    suffix[len - 1] = len;
    for (int i = len - 2; i >= 0; --i) {
        int j = 0;
        for (j = 0; j <= i; ++j) {
            if (pattern[i - j] != pattern[len - 1 - j]) {
                break;
            }
        }
        suffix[i] = j;
    }
}

void computeGoodSuffix(string pattern) {
    int len = pattern.length();
    goodSuffixVec = vector<int>(len, len - 1);

    int j = 0;
    for (int i = len - 1; i >= 0; --i) {
        if (suffix[i] == i + 1) {
            for (; j < len - 1 - i; ++j) {
                if (goodSuffixVec[j] == len) {
                    goodSuffixVec[j] = len - i - i;
                }
            }
        }
    }
    for (int i = 0; i < len - 1; ++i) {
        goodSuffixVec[len - 1 - suffix[i]] = len - 1 - i;
    }
}

void boyerMoore(string pattern, string str) {
    int patternLen = pattern.length();
    int strLen = str.length();
    computebadCharVec(pattern);
    computeSuffix(pattern);
    computeGoodSuffix(pattern);
    int j = 0, i = 0;
    while (j <= strLen - patternLen) {
        for (i = patternLen - 1; i >= 0 && pattern[i] == str[i + j]; --i);
        if (i < 0) {
            cout << j << endl;
            j += goodSuffixVec[0];
            continue;
        } else {
            j += max(badCharVec[str[i + j]] - patternLen + 1 + i,
                     goodSuffixVec[i]);
        }
    }
}

void print(vector<int> vec) {
    for (auto each : vec) {
        cout << each << " ";
    }
    cout << endl;
}

int main() {
    string str = "bcabababbcababab";
    string pattern = "bcababab";
    boyerMoore(pattern, str);
//    print(suffix);
//    print(badCharVec);
//    print(goodSuffixVec);
    return 0;
}
