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
    int n, m; ll x, k, y;
    cin >> n >> m >> x >> k >> y;
    vector<int> a(n), b(m);
    hash_map<int, int> pos;
    for (int i = 0; i < n; i++) cin >> a[i], pos[a[i]] = i;
    for (int i = 0; i < m; i++) cin >> b[i];

    int i = 0, j = 0;
    vector<pair<int, vector<int>>> remove;
    while (i < n && j < m) {
        if (a[i] == b[j]) {
            i++, j++;
            continue;
        }
        int lv = (i ? a[i - 1]: 0), l = i;
        while (i < n) {
            if (i < n && a[i] != b[j]) i++;
            else break;
        }
        if (i == n) {
            cout << "-1\n";
            return;
        }
        int rv = a[i];
        remove.push_back({max(lv, rv), vector<int>(a.begin() + l, a.begin() + i)});   
    }
    if (i < n) {
        remove.push_back({b.back(), vector<int>(a.begin() + i, a.end())});
    }
    if(j < m) {
        cout << "-1\n";
        return;
    }
    dbg(remove);
    ll ans = 0;
    bool fail = 0;
    for (auto &[mx, v] : remove) {
        ll vsz = (ll)v.size();
        ll mxv = *max_element(v.begin(), v.end());

        if (y * k <= x) {
            if (mx > mxv) {
                ans += y * vsz;
                continue;
            } else {
                if (vsz >= k) {
                    ans += x;
                    ans += y * (vsz - k);
                    continue;
                } else {
                    fail = 1;
                    break;
                }
            }
        } else {
            if (vsz < k) {
                if (mx > mxv) {
                    ans += y * vsz;
                    continue;
                } else {
                    fail = 1;
                    break;
                }
            } else {
                ans += (vsz / k) * x;
                vsz %= k;
                ans += y * vsz;
            }
        }
    }
    if(fail) {
        cout << "-1\n";
        return;
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << setprecision(15) << fixed;

    int TT = 1;
    // cin >> TT;
    while (TT--) {
        solve();
    }

    return 0;
}