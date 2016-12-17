class Solution {
private:
    void generateImpt(vector<string>& ans, string last, int RightPLeft, int LeftPLeft) {
        if (RightPLeft <= LeftPLeft) {
            if (LeftPLeft == 0) {
                ans.push_back(last);
            } else {
                if (RightPLeft > 0) {
                    generateImpt(ans, last + "(", RightPLeft - 1, LeftPLeft);
                }
                generateImpt(ans, last + ")", RightPLeft, LeftPLeft - 1);
            }
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        generateImpt(ans, "", n, n);
        return ans;
    }
};