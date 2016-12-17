int HashMap::_hash(const string key) {
    unsigned long long h=0,g;
    for (int i = 0; i < key.size(); ++i) {
        h = (h << 4) + key[i];
        g = h & 0Xf0000000L;
        if (g) {
            h ^= g >> 24;
        }
        h &= ~g;
    }
    h = h % 50;
    return h;
}