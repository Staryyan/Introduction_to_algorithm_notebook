/**
 * countSort.
 * 计数排序。
 * 适用于一定范围的排序。
 */
vector<int> counterSort(vector<int>& in, int range) {
    vector<int> counter(range + 1, 0);
    for (auto each : in) { counter[each]++; }
    for (int i = 1; i < counter.size(); ++i) { counter[i] += counter[i - 1]; }
    vector<int> out(in.size(), 0);
    for (int j = in.size() - 1; j >= 0; --j) {
        out[--counter[in[j]]] = in[j];
    }
    return out;
}
