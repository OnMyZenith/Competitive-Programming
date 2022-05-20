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

    int n, x; cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    // vector<int> idx(n);
    // iota(idx.begin(), idx.end(), 0);
    // sort(idx.begin(), idx.end(), [&](int i, int j){return a[i] < a[j];});

    // for (int i = 0; i < n; i++) {
    //     for (int l = i + 1; l < n; l++) {
    //         for (int j = l + 1, k = n - 1; j < k;) {
    //             ll s = a[idx[i]] + a[idx[l]] + a[idx[j]] + a[idx[k]];
    //             if(s > x) k--;
    //             else if(s < x) j++;
    //             else {
    //                 cout << idx[i] + 1 << " " << idx[l] + 1 << " " << idx[j] + 1 << " " << idx[k] + 1 << '\n';
    //                 return 0;
    //             }
    //         }
    //     }
    // }
    hash_map<int, vector<array<int, 2>>> mp;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            mp[a[i] + a[j]].push_back({i, j});
            auto it = mp.find(x - a[i] - a[j]);
            if (it != mp.end()) {
                for (auto &p : it->second) {
                    vector<int> v = {p[0], p[1], i, j};
                    if(set<int>(v.begin(), v.end()).size() == 4) {
                        cout << p[0] + 1 << " " << p[1] + 1 << " " << i + 1 << " " << j + 1 << '\n';
                        return 0;
                    }
                }
            }
        }
    }
    cout << "IMPOSSIBLE\n";
    return 0;
}