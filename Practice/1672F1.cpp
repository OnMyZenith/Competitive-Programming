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

template <class T>
void remDupf(vector<T> &v) { sort(v.begin(), v.end()), v.erase(unique(v.begin(), v.end()), end(v)); }
template <typename T_vector>
void ov(const T_vector &v, bool add_one = false, int start = -1, int end = -1) {
    if (start < 0) start = 0;
    if (end < 0) end = int(v.size());

    for (int i = start; i < end; i++)
        cout << v[i] + (add_one ? 1 : 0) << " \n"[i == end - 1];
}
template <class T>
bool ckmin(T &x, const T &y) { return (y < x) ? (x = y, 1) : 0; }
template <class T>
bool ckmax(T &x, const T &y) { return (y > x) ? (x = y, 1) : 0; }
struct splitmix64_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

template <class T, class U, typename Hash = splitmix64_hash>
using hash_map = gp_hash_table<T, U, Hash>;
template <class T, typename Hash = splitmix64_hash>
using hash_set = hash_map<T, null_type, Hash>;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> f(n);
    // hash_map<int, hash_set<int>> m;
    hash_set<int> s;
    int l = -1;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if(s.find(a[i]) == s.end()) {
            f[i] = 1; l = i;
            s.insert(a[i]);
        }
        // m[a[i]].insert(i);
    }
    int _l = l;
    dbg(l);
    for (int i = 0; i < _l; i++) {
        if(f[i]) {
            swap(a[i], a[l]);
            l = i;
        }
    }
    ov(a);

    // auto canbe = [&](int i, int x) -> bool {
    //     auto it = m[x].find(i);
    //     return it == m[x].end();
    // };

    // vector<int> _tmp(n);
    // iota(_tmp.begin(), _tmp.end(), 0);
    // hash_set<int> available(_tmp.begin(), _tmp.end());

    // vector<int> res(a);
    // vector<int> ord;

    // for (auto &[x, idxs] : m) {
    //     ord.push_back(x);
    // }

    // sort(ord.begin(), ord.end(), [&](int x, int y) { return m[x].size() > m[y].size(); });
    // dbg(ord);
    // int last = 0;
    // for (auto &x : ord) {
    //     for (int j = 0; j < (int)m[x].size(); j++) {
    //         for (auto &i : available) {
    //             if (canbe(i, x) && canbe(i, last)) {
    //                 res[i] = x;
    //                 available.erase(i);
    //                 break;
    //             }
    //         }
    //     }
    //     last = x;
    // }
    // ov(res);
}

int main() {
    vamos;

    int TT = 1;
    cin >> TT;
    while (TT--) {
        solve();
    }

    return 0;
}