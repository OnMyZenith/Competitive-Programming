/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
using ll = long long;

#define vamos ios_base::sync_with_stdio(false), cin.tie(nullptr), cout << setprecision(15) << fixed;
#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#endif

template <class T> struct max_segtree {
    // ALL INPUT FROM THE USER IS 0 BASED.
    int SZ; vector<T> v;

    constexpr int log_2(int x) { return x ? (8 * (int)sizeof(x)) - 1 - __builtin_clz(x) : -1; } // Floor of log_2(x); index of highest 1-bit
    constexpr int next_pow_2(int x) { return x > 0 ? 1 << log_2(2 * x - 1) : 0; }               // 16->16, 13->16, (x<=0)->0

    static constexpr T NEUTRAL_VAL = 0;  // Change this
    T f(T a, T b) { return max(a, b); };   // Change this

    // v i.e. the tree is indexed 1 based & a i.e. input data is indexed 0 based.
    void build(vector<T> &a) {
        SZ = 2 * next_pow_2(((int)a.size())); v.assign(SZ, NEUTRAL_VAL);
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

// Check result <= hi
template <class T, class U> T ft(T lo, T hi, U f) {
    ++hi, assert(lo <= hi);
    while (lo < hi) {
        T mid = lo + (hi - lo) / 2;
        f(mid) ? hi = mid : lo = mid + 1;
    }
    return lo;
}

template <typename T_vector> void ov(const T_vector &v, bool add_one = false, int start = -1, int end = -1) {
    if (start < 0) start = 0;
    if (end < 0) end = int(v.size());

    for (int i = start; i < end; i++)
        cout << v[i] + (add_one ? 1 : 0) << " \n"[i == end - 1];
}


int main() {
    vamos;

    int n; cin >> n;
    vector<int> c(n), a(2 * n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
        a[i] = a[i + n] = c[i];
    }
    max_segtree<int> t; t.build(a);
    vector<int> dont_start_here(n, -1), dies_after(n, 1e9);

    for (int i = 0; i < n; i++)  {
        int steps = ft(1, n - 1, [&](int m){
            return t.q(n + i - m, n + i - 1) > 2 * c[i];
        });
        if(steps != n) {
            dies_after[(i - steps + n) % n] = min(steps, dies_after[(i - steps + n) % n]);
        }
    }
    if(*min_element(dies_after.begin(), dies_after.end()) == 1e9) {
        while(n--) cout << -1 << " \n"[!n];
        return 0;
    }
    for (int i = 0; i < n; i++) {
        if(dies_after[i] < 1e9) {
            int curr = dies_after[i] + 1;
            for (int j = i - 1; j >= i - 2 * n; j--, curr++) {
                int idx = (j + 2 * n) % n;
                if(dies_after[idx] < 1e9) curr = min(curr, dies_after[idx]);
                dies_after[idx] = curr;
            }
            break;
        }
    }
    ov(dies_after);

    return 0;
}