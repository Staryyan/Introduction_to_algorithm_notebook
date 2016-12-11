/**
 * 3(n/2)次比较找到最大值和最小值。
 * @param in   [description]
 * @param _max [description]
 * @param _min [description]
 */
void findMaxAndMin(vector<int> in, int& _max, int& _min) {
    _max = INT_MIN, _min = INT_MAX;
    int start = 0, end = in.size() - 1;
    while (start <= end) {
        if (in[start] < in[end]) {
            _min = min(_min, in[start]);
            _max = max(_max, in[end]);
        } else {
            _min = min(_min, in[end]);
            _max = max(_max, in[start]);
        }
        start++;
        end--;
    }
}