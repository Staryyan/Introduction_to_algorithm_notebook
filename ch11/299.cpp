class Solution {
private:
    string int2str(int num) {
        stringstream ss;
        ss << num;
        return ss.str();
    }
public:
    string getHint(string secret, string guess) {
        int len = (int)secret.size();
        if (!len) { return ""; }
        map<char, int> charSet;
        for (auto each : secret) {
            charSet[each]++;
        }
        int bulls = 0, cows = 0;
        for (int i = 0; i < len; ++i) {
            if (secret[i] == guess[i]) {
                charSet[secret[i]]--;
                bulls++;
            }
        }
        for (int j = 0; j < len; ++j) {
            if (secret[j] != guess[j] && charSet[guess[j]] != 0) {
                charSet[guess[j]]--;
                cows++;
            }
        }
        return int2str(bulls) + "A" + int2str(cows) + "B";
    }
};