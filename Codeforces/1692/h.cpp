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
template <class T> bool ckmin(T &x, const T &y) { return (y < x) ? (x = y, 1) : 0; }
template <class T> bool ckmax(T &x, const T &y) { return (y > x) ? (x = y, 1) : 0; }

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    hash_map<int, pair<int, int>> dp;
    int best_guess = -1, best = 0;
    for (int i = 0; i < n; i++) {
        if(dp.find(a[i]) == dp.end()) {
            dp[a[i]] = {1, i};
            dbg(a[i], i);
        } else {
            dbg(dp[a[i]], i);
            dp[a[i]].first = dp[a[i]].first + 1 - max(i - dp[a[i]].second - 1, 0);
            dp[a[i]].second = i;
            dbg(dp[a[i]], i);
        }
        if(ckmax(best, dp[a[i]].first)) best_guess = a[i];
        if(dp.find(a[i]) != dp.end() && dp[a[i]].first <= 0) dp[a[i]] = {1, i};
    }
    dbg(dp);
    best = 0; int curr = 0;
    int right = -1, left = -1;
    for (int i = 0; i < n; i++) {
        curr += a[i] == best_guess;
        curr -= a[i] != best_guess;
        if(ckmax(best, curr)) right = i;
        ckmax(curr, 0);
    }
    curr = 0;
    for (int i = right; i >= 0; i--) {
        curr += a[i] == best_guess;
        curr -= a[i] != best_guess;
        if(curr == best) {
            left = i;
            break;
        }
    }

    cout << best_guess << " " << left + 1 << " " << right + 1 << '\n';
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