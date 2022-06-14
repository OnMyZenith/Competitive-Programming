/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include "bits/stdc++.h"
using namespace std;
using ll = long long;

#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#endif

#include <bits/extc++.h>
using namespace __gnu_pbds;

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

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<bool>> a(n, vector<bool>(m));
    vector<vector<bool>> vis(n, vector<bool>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0, x; j < m; j++) {
            cin >> x;
            a[i][j] = x;
        }
    }
    hash_map<int, array<int, 2>> power;

    for (int p = 1;; p++) {

        if(vis[min(p - 1, n - 1)][max(0, p - n)]) break;
        for (int r = min(p - 1, n - 1), c = max(0, p - n); r >= 0 && c < m; r--, c++) {
            if(a[r][c]) power[p][1]++;
            else power[p][0]++;
            vis[r][c] = 1;
            // dbg(r + 1, c + 1);
        }

        if(vis[max(n - p, 0)][m - 1 - max(0, p - n)]) {
            for (int r = min(p - 1, n - 1), c = max(0, p - n); r >= 0 && c < m; r--, c++) {
                if(a[r][c]) power[p][1]--;
                else power[p][0]--;
                vis[r][c] = 1;
                // dbg(r + 1, c + 1);
            }
            break;
        }
        for (int r = max(n - p, 0), c = m - 1 - max(0, p - n); r < n && c >= 0; r++, c--) {
            if(a[r][c]) power[p][1]++;
            else power[p][0]++;
            vis[r][c] = 1;
            // dbg(r + 1, c + 1);
        }
    }
    // dbg(vis);
    int ans = 0;
    for (auto &[x, y] : power) {
        dbg(y);
        ans += min(y[0], y[1]);
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << setprecision(15) << fixed;

    int TT = 1;
    cin >> TT;
    while(TT--) {
        solve();
    }

    return 0;
}