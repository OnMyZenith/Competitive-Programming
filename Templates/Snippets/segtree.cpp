tcT > struct segtree {
    // ALL INPUT FROM THE USER IS 0 BASED.
    int SZ;  V<T> v;

    static constexpr T NEUTRAL_VAL = iINF; // Change this
    T f(T a, T b) { return min(a, b); };   // Change this

    // v i.e. the tree is indexed 1 based & a i.e. input data is indexed 0 based.
    void build(V<T> &a) {
        SZ = 2 * next_pow_2(sz(a)); v.ass(SZ, NEUTRAL_VAL);
        f0r(i, sz(a)) v[SZ / 2 + i] = a[i];
        f1rd(i, SZ / 2 - 1, 1) v[i] = f(v[2 * i], v[2 * i + 1]);
    }

    // idx is 0 based
    void update(int idx, T x) {
        int i = SZ / 2 + idx; v[i] = x;
        for (i /= 2; i > 0; i /= 2)
            v[i] = f(v[2 * i], v[2 * i + 1]);
    }

    // ql, qr, lx and rx are 0 based, node is 1 based
    T q(int ql, int qr, int lx, int rx, int node) {
        if (ql <= lx && rx <= qr) return v[node];
        if (qr < lx || rx < ql) return NEUTRAL_VAL;
        return f(q(ql, qr, lx, (lx + rx) / 2, node * 2), q(ql, qr, (lx + rx) / 2 + 1, rx, node * 2 + 1));
    }

    // ql and qr are inclusive and 0 based
    T q(int ql, int qr) { return q(ql, qr, 0, SZ / 2 - 1, 1); }

    void printWillTLE() {
        int nodes = 1, spaces = SZ, idx = 1;
        while (idx < SZ) {
            f0r(j, nodes) {
                cout << setw(j ? 2 * spaces : spaces);
                if (v[idx] != NEUTRAL_VAL) pr(v[idx]); else pr('_');
                idx++;
            }
            cout << '\n'; nodes *= 2; spaces /= 2;
        }
        f0r(k, 2 * SZ) cout << "-\n"[k == 2 * SZ - 1];
    }
};