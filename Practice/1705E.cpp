/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include "bits/stdc++.h"
using namespace std;
// using ll = long long;

// #ifndef asr_debug
// #pragma GCC optimize("O3")
// #pragma GCC optimize("unroll-loops")
// // #pragma GCC optimize("Ofast")
// // Can casuse floating point errors, assumes associativeness for instance

// #pragma GCC target("avx2")
// #pragma GCC target("popcnt,lzcnt,bmi,bmi2,tune=native")
// // #pragma GCC target("avx,fma")
// // #pragma GCC target("sse4.2,fma")
// // run custom tests with stuff like assert(__builtin_cpu_supports("avx2"))
// // or use avx instead of sse4.2, leave fma in as it was covered in avx2
// #endif

#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#endif

// class segtree {
// public:
//     struct node {
//         // don't forget to set default value (used for leaves)
//         // not necessarily neutral element!
//         int mx = 0;
//         int mn = 0;
//         int add = 0;

//         void apply(int l, int r, int v) {
//             mn += v;
//             mx += v;
//             add += v;
//         }
//     };

//     node unite(const node &a, const node &b) const {
//         node res;
//         res.mn = min(a.mn, b.mn);
//         res.mx = max(a.mx, b.mx);
//         return res;
//     }

//     inline void push(int x, int l, int r) {
//         int y = (l + r) >> 1;
//         int z = x + ((y - l + 1) << 1);

//         if (tree[x].add != 0) {
//             tree[x + 1].apply(l, y, tree[x].add);
//             tree[z].apply(y + 1, r, tree[x].add);
//             tree[x].add = 0;
//         }
//     }

//     inline void pull(int x, int z) {
//         tree[x] = unite(tree[x + 1], tree[z]);
//     }

//     int n;
//     vector<node> tree;

//     void build(int x, int l, int r) {
//         if (l == r) {
//             return;
//         }
//         int y = (l + r) >> 1;
//         int z = x + ((y - l + 1) << 1);
//         build(x + 1, l, y);
//         build(z, y + 1, r);
//         pull(x, z);
//     }

//     template <typename M>
//     void build(int x, int l, int r, const vector<M> &v) {
//         if (l == r) {
//             tree[x].apply(l, r, v[l]);
//             return;
//         }
//         int y = (l + r) >> 1;
//         int z = x + ((y - l + 1) << 1);
//         build(x + 1, l, y, v);
//         build(z, y + 1, r, v);
//         pull(x, z);
//     }

//     node get(int x, int l, int r, int ll, int rr) {
//         if (ll <= l && r <= rr) {
//             return tree[x];
//         }
//         int y = (l + r) >> 1;
//         int z = x + ((y - l + 1) << 1);
//         push(x, l, r);
//         node res{};
//         if (rr <= y) {
//             res = get(x + 1, l, y, ll, rr);
//         } else {
//             if (ll > y) {
//                 res = get(z, y + 1, r, ll, rr);
//             } else {
//                 res = unite(get(x + 1, l, y, ll, rr), get(z, y + 1, r, ll, rr));
//             }
//         }
//         pull(x, z);
//         return res;
//     }

//     template <typename... M>
//     void modify(int x, int l, int r, int ll, int rr, const M &...v) {
//         if (ll <= l && r <= rr) {
//             tree[x].apply(l, r, v...);
//             return;
//         }
//         int y = (l + r) >> 1;
//         int z = x + ((y - l + 1) << 1);
//         push(x, l, r);
//         if (ll <= y) {
//             modify(x + 1, l, y, ll, rr, v...);
//         }
//         if (rr > y) {
//             modify(z, y + 1, r, ll, rr, v...);
//         }
//         pull(x, z);
//     }

//     int find_first_knowingly(int x, int l, int r, const function<bool(const node &)> &f) {
//         if (l == r) {
//             return l;
//         }
//         push(x, l, r);
//         int y = (l + r) >> 1;
//         int z = x + ((y - l + 1) << 1);
//         int res;
//         if (f(tree[x + 1])) {
//             res = find_first_knowingly(x + 1, l, y, f);
//         } else {
//             res = find_first_knowingly(z, y + 1, r, f);
//         }
//         pull(x, z);
//         return res;
//     }

//     int find_first(int x, int l, int r, int ll, int rr, const function<bool(const node &)> &f) {
//         if (ll <= l && r <= rr) {
//             if (!f(tree[x])) {
//                 return -1;
//             }
//             return find_first_knowingly(x, l, r, f);
//         }
//         push(x, l, r);
//         int y = (l + r) >> 1;
//         int z = x + ((y - l + 1) << 1);
//         int res = -1;
//         if (ll <= y) {
//             res = find_first(x + 1, l, y, ll, rr, f);
//         }
//         if (rr > y && res == -1) {
//             res = find_first(z, y + 1, r, ll, rr, f);
//         }
//         pull(x, z);
//         return res;
//     }

//     int find_last_knowingly(int x, int l, int r, const function<bool(const node &)> &f) {
//         if (l == r) {
//             return l;
//         }
//         push(x, l, r);
//         int y = (l + r) >> 1;
//         int z = x + ((y - l + 1) << 1);
//         int res;
//         if (f(tree[z])) {
//             res = find_last_knowingly(z, y + 1, r, f);
//         } else {
//             res = find_last_knowingly(x + 1, l, y, f);
//         }
//         pull(x, z);
//         return res;
//     }

//     int find_last(int x, int l, int r, int ll, int rr, const function<bool(const node &)> &f) {
//         if (ll <= l && r <= rr) {
//             if (!f(tree[x])) {
//                 return -1;
//             }
//             return find_last_knowingly(x, l, r, f);
//         }
//         push(x, l, r);
//         int y = (l + r) >> 1;
//         int z = x + ((y - l + 1) << 1);
//         int res = -1;
//         if (rr > y) {
//             res = find_last(z, y + 1, r, ll, rr, f);
//         }
//         if (ll <= y && res == -1) {
//             res = find_last(x + 1, l, y, ll, rr, f);
//         }
//         pull(x, z);
//         return res;
//     }

//     segtree(int _n) : n(_n) {
//         assert(n > 0);
//         tree.resize(2 * n - 1);
//         build(0, 0, n - 1);
//     }

//     template <typename M>
//     segtree(const vector<M> &v) {
//         n = v.size();
//         assert(n > 0);
//         tree.resize(2 * n - 1);
//         build(0, 0, n - 1, v);
//     }

//     node get(int ll, int rr) {
//         // dbg(ll, rr, n);
//         assert(0 <= ll && ll <= rr && rr <= n - 1);
//         return get(0, 0, n - 1, ll, rr);
//     }

//     node get(int p) {
//         assert(0 <= p && p <= n - 1);
//         return get(0, 0, n - 1, p, p);
//     }

//     template <typename... M>
//     void modify(int ll, int rr, const M &...v) {
//         assert(0 <= ll && ll <= rr && rr <= n - 1);
//         modify(0, 0, n - 1, ll, rr, v...);
//     }

//     // find_first and find_last call all FALSE elements
//     // to the left (right) of the sought position exactly once

//     int find_first(int ll, int rr, const function<bool(const node &)> &f) {
//         assert(0 <= ll && ll <= rr && rr <= n - 1);
//         return find_first(0, 0, n - 1, ll, rr, f);
//     }

//     int find_last(int ll, int rr, const function<bool(const node &)> &f) {
//         assert(0 <= ll && ll <= rr && rr <= n - 1);
//         return find_last(0, 0, n - 1, ll, rr, f);
//     }
// };


// Either globally or in a single class:
static char buf[250 << 20];
void* operator new(size_t s) {
	static size_t i = sizeof buf;
	assert(s < i);
	return (void*)&buf[i -= s];
}
void operator delete(void*) {}

const int inf = 1e9;

struct Node {
    Node *l = 0, *r = 0;
    int lo, hi;
    bool mset_bool = 0, mset_val = 0, mn_val = 0, mx_val = 0;
    Node(int _lo, int _hi) : lo(_lo), hi(_hi) {}
    Node(vector<bool> &v, int _lo, int _hi) : lo(_lo), hi(_hi) {
        if (lo + 1 < hi) {
            int mid = lo + (hi - lo) / 2;
            l = new Node(v, lo, mid);
            r = new Node(v, mid, hi);
            mx_val = max(l->mx_val, r->mx_val);
            mn_val = min(l->mn_val, r->mn_val);
        } else
            mx_val = v[lo], mn_val = v[lo];
    }
    bool q_mx(int L, int R) {
        if (R <= lo || hi <= L) return 0;
        if (L <= lo && hi <= R) return mx_val;
        push();
        return max(l->q_mx(L, R), r->q_mx(L, R));
    }
    bool q_mn(int L, int R) {
        if (R <= lo || hi <= L) return 1;
        if (L <= lo && hi <= R) return mn_val;
        push();
        return min(l->q_mn(L, R), r->q_mn(L, R));
    }
    void set(int L, int R, int x) {
        if (R <= lo || hi <= L) return;
        if (L <= lo && hi <= R) mset_bool = 1, mset_val = mx_val = mn_val = x;
        else {
            push(), l->set(L, R, x), r->set(L, R, x);
            mx_val = max(l->mx_val, r->mx_val);
            mn_val = min(l->mn_val, r->mn_val);
        }
    }
    // void add(int L, int R, int x) {
    //     if (R <= lo || hi <= L) return;
    //     if (L <= lo && hi <= R) {
    //         if (mset != inf) mset += x;
    //         else
    //             madd += x;
    //         mx_val += x;
    //         mn_val += x;
    //     } else {
    //         push(), l->add(L, R, x), r->add(L, R, x);
    //         mx_val = max(l->mx_val, r->mx_val);
    //         mn_val = min(l->mn_val, r->mn_val);
    //     }
    // }
    void push() {
        if (!l) {
            int mid = lo + (hi - lo) / 2;
            l = new Node(lo, mid);
            r = new Node(mid, hi);
        }
        if (mset_bool)
            l->set(lo, hi, mset_val), r->set(lo, hi, mset_val), mset_bool = 0;
        // else if (madd)
        //     l->add(lo, hi, madd), r->add(lo, hi, madd), madd = 0;
    }
};

const int N = 2e5 + 30;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << setprecision(15) << fixed;

    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    vector<int> f(N);
    for (int i = 0; i < n; i++)
        cin >> a[i], f[a[i]]++;


    vector<bool> fr(N);
    for (int i = 0; i < N - 1; i++) {
        f[i + 1] += f[i] / 2;
        f[i] %= 2;
        fr[i] = f[i];
    }

    Node *tr = new Node(fr, 0, (int)fr.size());

    // segtree tree(N);
    // tree.build(0, 0, N - 1, f);

    while (q--) {
        int idx, new_val;
        cin >> idx >> new_val;
        idx--;
        int prev_val = a[idx];
        a[idx] = new_val;

        // if (tree.get(prev_val).mx == 0) {
        if (tr->q_mx(prev_val, prev_val + 1) == 0) {
            int lo = prev_val, hi = N - 1;
            while (lo < hi) {
                int mid = (lo + hi) / 2;
                if (tr->q_mx(lo, mid + 1) == 0) lo = mid + 1;
                else
                    hi = mid;
            }
            tr->set(lo, lo + 1, 0);
            tr->set(prev_val, lo, 1);
            // tree.modify(lo, lo, -1);
            // tree.modify(prev_val, lo - 1, 1);

        } else {
            // tree.modify(prev_val, prev_val, -1);
            tr->set(prev_val, prev_val + 1, 0);
        }

        if (tr->q_mx(new_val, new_val + 1) == 0) {
            // tree.modify(new_val, new_val, 1);
            tr->set(new_val, new_val + 1, 1);
        } else {
            int lo = new_val, hi = N - 1;
            while (lo < hi) {
                int mid = (lo + hi) / 2;
                if (tr->q_mn(lo, mid + 1) == 1) lo = mid + 1;
                else
                    hi = mid;
            }
            tr->set(lo, lo + 1, 1);
            tr->set(new_val, lo, 0);
            // tree.modify(lo, lo, 1);
            // tree.modify(new_val, lo - 1, -1);
        }

        int lo = 0, hi = N - 1;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (tr->q_mx(mid, hi + 1) == 0) hi = mid;
            else
                lo = mid + 1;
        }
        cout << lo - 1 << '\n';
    }
    return 0;
}
