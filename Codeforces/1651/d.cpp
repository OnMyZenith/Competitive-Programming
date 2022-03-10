/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
using ll = long long;

#ifndef asr_debug
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
// #pragma GCC optimize("Ofast")
// Can casuse floating point errors, assumes associativeness for instance

#pragma GCC target("avx2")
#pragma GCC target("popcnt,lzcnt,bmi,bmi2,tune=native")
// #pragma GCC target("avx,fma")
// #pragma GCC target("sse4.2,fma")
// run custom tests with stuff like assert(__builtin_cpu_supports("avx2"))
// or use avx instead of sse4.2, leave fma in as it was covered in avx2
#endif


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
    size_t operator()(pair<uint64_t, uint64_t> x) const {
        static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x.first + FIXED_RANDOM) ^ splitmix64(x.second + FIXED_RANDOM);
    }
};

template <class T, class U, typename Hash = splitmix64_hash> using hash_map = gp_hash_table<T, U, Hash>;
template <class T, typename Hash = splitmix64_hash> using hash_set = hash_map<T, null_type, Hash>;


const int dr[4] = {-1, 0, 1, 0}, dc[4] = {0, 1, 0, -1}; // URDL
const char dir[4] = {'U', 'R', 'D', 'L'};


int main() {
    vamos;

    int n; cin >> n;
    vector<pair<int,int>> p(n);
    hash_map<pair<int, int>, int> idx;
    for (int i = 0; i < n; i++) {
        auto &[x, y] = p[i];
        cin >> x >> y; x--, y--;
        idx[{x, y}] = i;
    }
    hash_set<pair<int, int>> path(p.begin(), p.end());
    vector<bool> ans(n);
    vector<pair<int, int>> res(n);

    queue<pair<int, int>> q1, q2;

    for (int i = 0; i < n; i++) {
        auto &[r, c] = p[i];
        for (int j = 0; j < 4; j++) {
            if (path.find({r + dr[j], c + dc[j]}) == path.end()) {
                q1.push({r, c});
                ans[i] = 1; res[i] = {r + dr[j], c + dc[j]};
                break;
            }
        }
    }

    while(!q1.empty()) {
        auto [r, c] = q1.front(); q1.pop();

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(path.find({nr, nc}) != path.end() && !ans[idx[{nr, nc}]]) {
                q2.push({nr, nc});
                res[idx[{nr, nc}]] = res[idx[{r, c}]];
                ans[idx[{nr, nc}]] = 1;
            }
        }
        if(q1.empty()) swap(q1, q2);
    }
    for (int i = 0; i < n; i++) {
        cout << res[i].first + 1 << " " << res[i].second + 1 << '\n';
    }
    return 0;
}