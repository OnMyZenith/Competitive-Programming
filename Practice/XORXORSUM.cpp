/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include "bits/stdc++.h"
using namespace std;
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

#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#endif

#include <bits/extc++.h>
using namespace __gnu_pbds;

struct splitmix64_hash {
    // static uint64_t splitmix64(uint64_t x) {
    //     // http://xorshift.di.unimi.it/splitmix64.c
    //     x += 0x9e3779b97f4a7c15;
    //     x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    //     x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    //     return x ^ (x >> 31);
    // }

    // size_t operator()(uint64_t x) const {
    //     static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
    //     return splitmix64(x + FIXED_RANDOM);
    // }

    // size_t operator()(pair<uint64_t, uint64_t> x) const {
    //     static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
    //     return splitmix64(x.first + FIXED_RANDOM) ^ (splitmix64(x.second + FIXED_RANDOM) >> 1);
    // }

    // Comment everything above for this to work
    // Won't work with debug flags
    static __uint128_t splitmix64(__uint128_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15 * 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 60)) * 0xbf58476d1ce4e5b9 * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 57)) * 0x94d049bb133111eb * 0x94d049bb133111eb;
        return x ^ (x >> 62);
    }
    __uint128_t operator()(__uint128_t x) const {
        static const __uint128_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

template <class T, class U, typename Hash = splitmix64_hash>
using hash_map = gp_hash_table<T, U, Hash>;
template <class T, typename Hash = splitmix64_hash>
using hash_set = hash_map<T, null_type, Hash>;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << setprecision(15) << fixed;

    // int n = 100;
    // for (int i = 0; i < n; i++) {
    //     for (int j = i; j < n; j++) {
    //         if (i + j == 2 * (i ^ j)) {
    //             cout << "----------\n";
    //             cout << bitset<8>(i) << '\n';
    //             cout << bitset<8>(j) << '\n';
    //             cout << bitset<8>(i ^ j) << "<- XOR" << '\n';
    //             cout << bitset<8>(i + j) << "<- SUM" << '\n';
    //         }
    //     }
    // }
    int n; cin >> n;
    const int MX = 65;
    vector<ll> a(n);
    hash_map<__int128_t, int> cnt;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        __int128_t val = 0;
        __int128_t want = 0;
        for (int j = 0; j < MX - 1; j++, val *= 3, want *= 3) {
            bool jth = a[i] >> j & 1;
            if (!jth) continue;
            j++;
            bool j1th = a[i] >> j & 1;
            val += j1th ? 1 : 2;
            want += j1th ? 2 : 1;
            val *= 3, want *= 3;
        }
        ans += cnt[want];
        cnt[val]++;
    }
    cout << ans << '\n';

    return 0;
}
