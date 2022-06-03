/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#endif

template <class T> struct segtree {
    // ALL INPUT FROM THE USER IS 0 BASED.
    int SZ; vector<T> v;

    constexpr int pct(int x) { return __builtin_popcount(x); }                                  // # of bits set
    constexpr int log_2(int x) { return x ? (8 * (int)sizeof(x)) - 1 - __builtin_clz(x) : -1; } // Floor of log_2(x); index of highest 1-bit
    constexpr int log_2_ceil(int x) { return log_2(x) + int(__builtin_popcount(x) != 1); }      // Ceil of log_2(x);
    constexpr int contained_pow_2(int x) { return x > 0 ? 1 << log_2_ceil(x) : 0; }             // 16->16, 13->16, (x<=0)->0; Smallest number that's a power of 2, that's not smaller than x

    static constexpr T NEUTRAL_VAL = 0;  // Change this
    T f(T a, T b) { return (a ^ b); };   // Change this

    segtree(vector<int>&_v) {
        if(!_v.empty()) {
            build(_v);
        }
    }

    // v i.e. the tree is indexed 1 based & a i.e. input data is indexed 0 based.
    void build(vector<T> &a) {
        SZ = 2 * contained_pow_2(((int)a.size())); v.assign(SZ, NEUTRAL_VAL);
        for (int i = 0; i < ((int)a.size()); i++) v[SZ / 2 + i] = a[i];
        for (int i = SZ / 2 - 1; i >= 1; i--) v[i] = f(v[2 * i], v[2 * i + 1]);
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

    void print() {
#ifdef asr_debug
        int nodes = 1, spaces = SZ, idx = 1;
        while (idx < SZ) {
            for (int j = 0; j < nodes; j++) {
                cout << setw(j ? 2 * spaces : spaces);
                if (v[idx] != NEUTRAL_VAL) cout << (v[idx]); else cout << ('_');
                idx++;
            }
            cout << '\n'; nodes *= 2; spaces /= 2;
        }
        for (int k = 0; k < 2 * SZ; k++) cout << "-\n"[k == 2 * SZ - 1];
#endif
    }
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << setprecision(15) << fixed;

    int n, q; cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    segtree<int> tr(a);

    while(q--) {
        int l, r; cin >> l >> r;
        cout << tr.q(l - 1, r - 1) << '\n';
    }
    return 0;
}