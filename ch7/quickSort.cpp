int partition(vector<int>& vec, int left, int right) {
    int x = vec[right];
    int i = left - 1;
    for (int j = left; j < right; ++j) {
        if (vec[j] < x) {
            i++;
            swap(vec[i], vec[j]);
        }
    }
    swap(vec[i + 1], vec[right]);
    return i + 1;
}
void quickSortImpl(vector<int>& vec, int start, int end) {
    if (start < end) {
        int mid = partition(vec, start, end);
        quickSortImpl(vec, start, mid - 1);
        quickSortImpl(vec, mid + 1, end);
    }
}
void quickSort(vector<int>& vec) {
    quickSortImpl(vec, 0, (int)vec.size() - 1);
}