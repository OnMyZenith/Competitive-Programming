/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
using ll = long long;

#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#endif

template <class Fun>
class y_combinator_result {
    Fun fun_;
public:
    template <class T> explicit y_combinator_result(T &&fun) : fun_(std::forward<T>(fun)) {}
    template <class... Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template <class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }

template <class T> bool ckmin(T &x, const T &y) { return (y < x) ? (x = y, 1) : 0; }
template <class T> bool ckmax(T &x, const T &y) { return (y > x) ? (x = y, 1) : 0; }

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
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << setprecision(15) << fixed;

    int n, x; cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<array<int, 2>> best(1 << n, {n + 1, 0});
    best[0] = {1, 0};
    for (int mask = 1; mask < (1 << n); mask++) {
        for (int i = 0; i < n; i++) {
            if((mask >> i) & 1) {
                array<int, 2> without = best[mask ^ (1 << i)];
                if(a[i] + without[1] > x) {
                    without[0]++;
                    without[1] = min(without[1], a[i]);
                } else {
                    without[1] += a[i];
                }
                ckmin(best[mask], without);
            }
        }
    }
    cout << best[(1 << n) - 1][0] << '\n';


    // hash_map<int, array<int, 2>> mp;
    // cout << y_combinator([&](auto req_last, int mask) -> array<int, 2> {
    //     if(mask == 0) return {1, 0};
    //     auto it = mp.find(mask);
    //     if(it != mp.end()) return it->second;
    //     array<int, 2> best = {21, 0};
    //     for (int i = 0; i < n; i++) {
    //         if((mask >> i) & 1) {
    //             int last = a[i];
    //             auto without = req_last(mask ^ (1 << i));
    //             if(without[1] + last > x) {
    //                 if(best[0] >= without[0] + 1) {
    //                     best[0] = without[0] + 1;
    //                     best[1] = min(without[1], last);
    //                 }
    //             } else {
    //                 if(ckmin(best[0], without[0])) best[1] = without[1] + last;
    //                 else if (best[0] == without[0]) ckmin(best[1], without[1] + last);
    //             }
    //         }
    //     }
    //     mp[mask] = best;
    //     return best;
    // })((1 << n) - 1)[0] << '\n';

    return 0;
}