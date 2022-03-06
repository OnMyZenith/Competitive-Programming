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

template <class T, class U, typename Hash = splitmix64_hash> using hash_map = gp_hash_table<T, U, Hash>;
template <class T, typename Hash = splitmix64_hash> using hash_set = hash_map<T, null_type, Hash>;


int main() {
    vamos;

    int n, m; cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (auto &r : a) {
        for (auto &c : r) {
            cin >> c;
        }
    }
    hash_map<int, vector<int>> allr, allc;
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            allr[a[r][c]].push_back(r);
            allc[a[r][c]].push_back(c);
        }
    }
    ll ans = 0;
    for (auto &[c, v] : allr) {
        sort(v.rbegin(), v.rend());
        // dbg(c, v);
        int N = (int)v.size();
        vector<ll> pre(N + 1);
        for (ll i = 0; i < N; i++) {
            pre[i + 1] = pre[i] + v[i];
            ans += pre[i] - i * v[i];
        }
    }
    for (auto &[c, v] : allc) {
        sort(v.rbegin(), v.rend());
        // dbg(c, v);
        int N = (int)v.size();
        vector<ll> pre(N + 1);
        for (ll i = 0; i < N; i++) {
            pre[i + 1] = pre[i] + v[i];
            ans += pre[i] - i * v[i];
        }
    }
    cout << ans << '\n';
    return 0;
}