/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include "bits/stdc++.h"
using namespace std;
// using ll = long long;

#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#endif

class segtree {
public:
    struct node {
        // don't forget to set default value (used for leaves)
        // not necessarily neutral element!
        int mx = 0;
        int mn = 0;
        int add = 0;

        void apply(int l, int r, int v) {
            mn += v;
            mx += v;
            add += v;
        }
    };

    node unite(const node &a, const node &b) const {
        node res;
        res.mn = min(a.mn, b.mn);
        res.mx = max(a.mx, b.mx);
        return res;
    }

    inline void push(int x, int l, int r) {
        int y = (l + r) >> 1;
        int z = x + ((y - l + 1) << 1);

        if (tree[x].add != 0) {
            tree[x + 1].apply(l, y, tree[x].add);
            tree[z].apply(y + 1, r, tree[x].add);
            tree[x].add = 0;
        }
    }

    inline void pull(int x, int z) {
        tree[x] = unite(tree[x + 1], tree[z]);
    }

    int n;
    vector<node> tree;

    void build(int x, int l, int r) {
        if (l == r) {
            return;
        }
        int y = (l + r) >> 1;
        int z = x + ((y - l + 1) << 1);
        build(x + 1, l, y);
        build(z, y + 1, r);
        pull(x, z);
    }

    template <typename M>
    void build(int x, int l, int r, const vector<M> &v) {
        if (l == r) {
            tree[x].apply(l, r, v[l]);
            return;
        }
        int y = (l + r) >> 1;
        int z = x + ((y - l + 1) << 1);
        build(x + 1, l, y, v);
        build(z, y + 1, r, v);
        pull(x, z);
    }

    node get(int x, int l, int r, int ll, int rr) {
        if (ll <= l && r <= rr) {
            return tree[x];
        }
        int y = (l + r) >> 1;
        int z = x + ((y - l + 1) << 1);
        push(x, l, r);
        node res{};
        if (rr <= y) {
            res = get(x + 1, l, y, ll, rr);
        } else {
            if (ll > y) {
                res = get(z, y + 1, r, ll, rr);
            } else {
                res = unite(get(x + 1, l, y, ll, rr), get(z, y + 1, r, ll, rr));
            }
        }
        pull(x, z);
        return res;
    }

    template <typename... M>
    void modify(int x, int l, int r, int ll, int rr, const M &...v) {
        if (ll <= l && r <= rr) {
            tree[x].apply(l, r, v...);
            return;
        }
        int y = (l + r) >> 1;
        int z = x + ((y - l + 1) << 1);
        push(x, l, r);
        if (ll <= y) {
            modify(x + 1, l, y, ll, rr, v...);
        }
        if (rr > y) {
            modify(z, y + 1, r, ll, rr, v...);
        }
        pull(x, z);
    }

    int find_first_knowingly(int x, int l, int r, const function<bool(const node &)> &f) {
        if (l == r) {
            return l;
        }
        push(x, l, r);
        int y = (l + r) >> 1;
        int z = x + ((y - l + 1) << 1);
        int res;
        if (f(tree[x + 1])) {
            res = find_first_knowingly(x + 1, l, y, f);
        } else {
            res = find_first_knowingly(z, y + 1, r, f);
        }
        pull(x, z);
        return res;
    }

    int find_first(int x, int l, int r, int ll, int rr, const function<bool(const node &)> &f) {
        if (ll <= l && r <= rr) {
            if (!f(tree[x])) {
                return -1;
            }
            return find_first_knowingly(x, l, r, f);
        }
        push(x, l, r);
        int y = (l + r) >> 1;
        int z = x + ((y - l + 1) << 1);
        int res = -1;
        if (ll <= y) {
            res = find_first(x + 1, l, y, ll, rr, f);
        }
        if (rr > y && res == -1) {
            res = find_first(z, y + 1, r, ll, rr, f);
        }
        pull(x, z);
        return res;
    }

    int find_last_knowingly(int x, int l, int r, const function<bool(const node &)> &f) {
        if (l == r) {
            return l;
        }
        push(x, l, r);
        int y = (l + r) >> 1;
        int z = x + ((y - l + 1) << 1);
        int res;
        if (f(tree[z])) {
            res = find_last_knowingly(z, y + 1, r, f);
        } else {
            res = find_last_knowingly(x + 1, l, y, f);
        }
        pull(x, z);
        return res;
    }

    int find_last(int x, int l, int r, int ll, int rr, const function<bool(const node &)> &f) {
        if (ll <= l && r <= rr) {
            if (!f(tree[x])) {
                return -1;
            }
            return find_last_knowingly(x, l, r, f);
        }
        push(x, l, r);
        int y = (l + r) >> 1;
        int z = x + ((y - l + 1) << 1);
        int res = -1;
        if (rr > y) {
            res = find_last(z, y + 1, r, ll, rr, f);
        }
        if (ll <= y && res == -1) {
            res = find_last(x + 1, l, y, ll, rr, f);
        }
        pull(x, z);
        return res;
    }

    segtree(int _n) : n(_n) {
        assert(n > 0);
        tree.resize(2 * n - 1);
        build(0, 0, n - 1);
    }

    template <typename M>
    segtree(const vector<M> &v) {
        n = v.size();
        assert(n > 0);
        tree.resize(2 * n - 1);
        build(0, 0, n - 1, v);
    }

    node get(int ll, int rr) {
        // dbg(ll, rr, n);
        assert(0 <= ll && ll <= rr && rr <= n - 1);
        return get(0, 0, n - 1, ll, rr);
    }

    node get(int p) {
        assert(0 <= p && p <= n - 1);
        return get(0, 0, n - 1, p, p);
    }

    template <typename... M>
    void modify(int ll, int rr, const M &...v) {
        assert(0 <= ll && ll <= rr && rr <= n - 1);
        modify(0, 0, n - 1, ll, rr, v...);
    }

    // find_first and find_last call all FALSE elements
    // to the left (right) of the sought position exactly once

    int find_first(int ll, int rr, const function<bool(const node &)> &f) {
        assert(0 <= ll && ll <= rr && rr <= n - 1);
        return find_first(0, 0, n - 1, ll, rr, f);
    }

    int find_last(int ll, int rr, const function<bool(const node &)> &f) {
        assert(0 <= ll && ll <= rr && rr <= n - 1);
        return find_last(0, 0, n - 1, ll, rr, f);
    }
};

const int N = 2e5 + 20;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << setprecision(15) << fixed;

    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    vector<int> f(N);
    for (int i = 0; i < n; i++)
        cin >> a[i], f[a[i]]++;


    for (int i = 0; i < N - 1; i++) {
        f[i + 1] += f[i] / 2;
        f[i] %= 2;
    }

    segtree tree(N);
    tree.build(0, 0, N - 1, f);

    while (q--) {
        int idx, new_val;
        cin >> idx >> new_val;
        idx--;
        int prev_val = a[idx];
        a[idx] = new_val;

        // segment segp = tree.query(prev_val, prev_val + 1);
        // tree.get(prev_val);
        // dbg(q);
        if (tree.get(prev_val).mx == 0) {
            int lo = prev_val, hi = N - 1;
            while (lo < hi) {
                int mid = (lo + hi) / 2;
                // segment seg = tree.query(lo, mid + 1);
                if (tree.get(lo, mid).mx == 0) lo = mid + 1;
                else
                    hi = mid;
            }
            // dbg(lo);
            int index = lo;
            tree.modify(index, index, -1);
            tree.modify(prev_val, index - 1, 1);

            // tree.update(index, index + 1, segment_change(int(-1)));
            // tree.update(prev_val, index, segment_change(int(1)));
        } else {
            tree.modify(prev_val, prev_val, -1);
            // tree.update(prev_val, prev_val + 1, segment_change(int(-1)));
        }

        // segment segn = tree.query(new_val, new_val + 1);
        if (tree.get(new_val).mx == 0) {
            tree.modify(new_val, new_val, 1);
            // tree.update(new_val, new_val + 1, segment_change(int(1)));
        } else {
            int lo = new_val, hi = N - 1;
            while (lo < hi) {
                int mid = (lo + hi) / 2;
                // segment seg = tree.query(lo, mid + 1);
                if (tree.get(lo, mid).mn == 1) lo = mid + 1;
                else
                    hi = mid;
            }
            tree.modify(lo, lo, 1);
            tree.modify(new_val, lo - 1, -1);
            // tree.update_single(lo, segment(int(1), 1, int(1), int(1), 0));
            // tree.update(new_val, lo, segment_change(int(-1)));
        }
        int lo = 0, hi = N - 1;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            // segment seg = tree.query(mid, hi + 1);
            if (tree.get(mid, hi).mx == 0) hi = mid;
            else
                lo = mid + 1;
        }
        cout << lo - 1 << '\n';
    }
    return 0;
}
