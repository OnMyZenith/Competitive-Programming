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


template <class T> bool ckmin(T &x, const T &y) { return (y < x) ? (x = y, 1) : 0; }
template <class T> bool ckmax(T &x, const T &y) { return (y > x) ? (x = y, 1) : 0; }

// vector<int> primes;
// vector<long long> trial_division4(long long n) {
//     vector<long long> factorization;
//     for (long long d : primes) {
//         if (d * d > n)
//             break;
//         while (n % d == 0) {
//             factorization.push_back(d);
//             n /= d;
//         }
//     }
//     if (n > 1)
//         factorization.push_back(n);
//     return factorization;
// }

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


template <class Fun>
class y_combinator_result {
    Fun fun_;
public:
    template <class T> explicit y_combinator_result(T &&fun) : fun_(std::forward<T>(fun)) {}
    template <class... Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template <class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }


void solve() {
    int n, Q; cin >> n >> Q;
    vector<int> a(n);
    for (auto &u : a) {
        cin >> u;
    }
    hash_map<pair<int, int>, int> res;
    auto calc = [&](int ele, int l, int r) -> int {
        int g = 1;
        for (int i = l; i <= r; i++) {
            ckmax(g, gcd(ele, a[i]));
        }
        return g;
    };
    auto go = y_combinator([&](auto self, int l, int r) -> int {
        if(l >= r) return 1;
        auto it = res.find(pair<int, int>{l, r});
        if(it != res.end()) return it->second;
        int g = max({self(l + 1, r), self(l, r - 1), calc(a[l], l + 1, r), calc(a[r], l, r - 1)});
        res[{l, r}] = g;
        return g;
    });
    // int p = (int)primes.size();
    while(Q--) {
        int l, r; cin >> l >> r; l--, r--;
        // int g = 1;
        // for (int i = l; i <= r; i++) {
        //     for (int j = i + 1; j <= r; j++) {
        //         ckmax(g, gcd(a[i], a[j]));
        //     }
        // }
        // cout << g << '\n';
        cout << go(l, r) << '\n';
    }
}

int main() {
    vamos;
    // int n = 1e5;
    // vector<bool> is_prime(n+1, true);
    // is_prime[0] = is_prime[1] = false;
    // for (int i = 2; i * i <= n; i++) {
    //     if (is_prime[i]) {
    //         for (int j = i * i; j <= n; j += i)
    //             is_prime[j] = false;
    //     }
    // }
    // for (int i = 0; i < 1e5; i++) {
    //     if(is_prime[i]) primes.push_back(i);
    // }
    int TT = 1;
    cin >> TT;
    while(TT--) {
        solve();
    }

    return 0;
}