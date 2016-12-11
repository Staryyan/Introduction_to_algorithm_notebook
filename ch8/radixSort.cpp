/**
 * 适用于每个数都是d位的排序。
 * 可以适用于大数据的排序。
 * o(n).
 */
vector<string> radixSortImpl(vector<string> in, int index) {
    for (int j = 0; j < counter.size(); j++) { counter[j] = 0; }
    for (auto each : in) { counter[each[index] - '0']++; }
    for (int i = 1; i < counter.size(); ++i) { counter[i] += counter[i - 1]; }
    vector<string> out(in.size(), "");
    cout << out[0] << endl;
    for (int j = in.size() - 1; j >= 0; --j) {
        out[--counter[in[j][index] - '0']] = in[j];
    }
    return out;
}
vector<string> radixSort(vector<int>& in, int d) {
    vector<string> out(in.size(), "");
    for (int i = 0; i < in.size(); ++i) { out[i] = int2str(in[i]); }
    for (int j = 0; j < d; ++j) {
        out = radixSortImpl(out, j);
    }
    return out;
}