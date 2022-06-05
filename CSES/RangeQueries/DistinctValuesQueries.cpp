/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include <bits/stdc++.h>
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

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << setprecision(15) << fixed;

    int n, q; cin >> n >> q;
    vector<int> v(n), pre(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    vector<pair<int, int>> Q(q);
    for (int i = 0; i < q; i++) {
        int l, r; cin >> l >> r; l--;
        Q[i] = {l, r};
    }
    vector<int> ans(q), idx(q);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int i, int j){
        return Q[i] < Q[j];
    });
    hash_map<int, int> mp;
    int kicked_out = 0, taken_in = 0;
    for (int i = 0; i < q; i++)  {
        auto &[L, R] = Q[idx[i]];
        while (taken_in < R) mp[v[taken_in++]]++;
        while (kicked_out < L) {
            mp[v[kicked_out]]--;
            if (!mp[v[kicked_out]]) mp.erase(v[kicked_out]);
            kicked_out++;
        }
        ans[idx[i]] = (int)mp.size();
    }
    for (int i = 0; i < q; i++) {
        cout << ans[i] << '\n';
    }

    return 0;
}