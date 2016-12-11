class Solution {
private:
    string int2str(int num) {
        stringstream ss;
        ss << num;
        return ss.str();
    }
    bool compare(string str1, string str2) {
        return str1 + str2 >= str2 + str1;
    }
    int partition(vector<string>& vec, int left, int right) {
        string x = vec[right];
        int i = left - 1;
        for (int j = left; j < right; ++j) {
            if (compare(vec[j], x)) {
                i++;
                swap(vec[j], vec[i]);
            }
        }
        swap(vec[i + 1], vec[right]);
        return i + 1;
    }
    void quickSort(vector<string>& vec, int left, int right) {
        if (left < right) {
            int mid = partition(vec, left, right);
            quickSort(vec, left, mid - 1);
            quickSort(vec, mid + 1, right);
        }
    }
public:
    string largestNumber(vector<int>& nums) {
        if (nums.size() == 0) { return "0"; }
        vector<string> strNum(nums.size(), "");
        for (int i = 0; i < nums.size(); ++i) {
            strNum[i] = int2str(nums[i]);
        }
        quickSort(strNum, 0, strNum.size() - 1);
        string ans;
        for (auto each : strNum) {
            ans += each;
        }
        if (ans[0] == '0') { return "0"; }
        return ans;
    }
};