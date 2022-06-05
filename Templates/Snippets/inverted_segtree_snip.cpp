// Segment Tree supporting Modification on interval, Single element access
template <class T> struct inverted_segtree {
    int N; vector<T> v;

    // v i.e. the tree is indexed 1 based & arr i.e. input data is indexed 0 based.
    inverted_segtree(vector<T> &arr) {
        N = 1; while (N < (int)arr.size()) N <<= 1;
        v.resize(N << 1, 0);
        for (int i = 0; i < ((int)arr.size()); i++) v[N + i] = arr[i];
    }

    // [l, r) Half-Intervals
    void add(int l, int r, T x) {
        for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
            if (l & 1) v[l++] += x;
            if (r & 1) v[--r] += x;
        }
    }

    // idx is 0 based
    T query(int idx) {
        T res = v[idx += N];
        for (; idx >>= 1;) res += v[idx];
        return res;
    }

    void push() {
        for (int i = 1; i < N; i++) v[i << 1] += v[i], v[i << 1 | 1] += v[i], v[i] = 0;
    }
};
